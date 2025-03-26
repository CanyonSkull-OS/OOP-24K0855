#include <iostream>
#include <string>
using namespace std;

class Comment {
    string content;

public:
    Comment(const string &_content) : content(_content) {}

    void editContent(const string &newContent) {
        content = newContent;
    }

    string getContent() const {
        return content;
    }
};

class Post {
    string title;
    string content;
    Comment** comments;
    int numComments;

public:
    Post(const string &_title, const string &_content) : title(_title), content(_content), numComments(0) {
        comments = new Comment*[10]; 
    }

    void addComment(Comment *comment) {
        if (numComments < 10) {
            comments[numComments++] = comment;
        }
    }

    void removeComment(Comment *comment) {
        for (int i = 0; i < numComments; i++) {
            if (comments[i] == comment) {
                for (int j = i; j < numComments - 1; j++) {
                    comments[j] = comments[j + 1];
                }
                numComments--;
                break;
            }
        }
    }

    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
        cout << "Number of Comments: " << numComments << endl;
        for (int i = 0; i < numComments; i++) {
            cout << "- " << comments[i]->getContent() << endl;
        }
    }

    ~Post() {
        delete[] comments;
    }
};

class User {
    string name;
    int numPosts;
    
    public:
    Post** posts;
    User(const string &_name) : name(_name), numPosts(0) {
        posts = new Post*[10];
    }

    void createPost(const string &title, const string &content) {
        if (numPosts < 10) {
            posts[numPosts++] = new Post(title, content);
        }
    }

    void addCommentToPost(Post *post, Comment *comment) {
        for (int i = 0; i < numPosts; i++) {
            if (posts[i] == post) {
                posts[i]->addComment(comment);
            }
        }
    }

    void removeCommentFromPost(Post *post, Comment *comment) {
        for (int i = 0; i < numPosts; i++) {
            if (posts[i] == post) {
                posts[i]->removeComment(comment);
            }
        }
    }

    void displayUserPostsAndComments() const {
        cout << "User: " << name << endl;
        for (int i = 0; i < numPosts; i++) {
            posts[i]->displayInfo();
            cout << endl;
        }
    }

    ~User() {
        for (int i = 0; i < numPosts; i++) {
            delete posts[i];
        }
        delete[] posts;
    }
};

int main() {
    User user("Shafique Rehman");

    user.createPost("My Vacation Adventure", "Looks amazing!");
    user.createPost("Homemade Dinner", "I wish I could go there too");

    Post *vacationPost = user.posts[0];
    Post *dinnerPost = user.posts[1];

    Comment *comment1 = new Comment("Yum, what's the recipe?");
    Comment *comment2 = new Comment("Can I come over for dinner?");

    user.addCommentToPost(dinnerPost, comment1);
    user.addCommentToPost(dinnerPost, comment2);

    user.displayUserPostsAndComments();

    comment1->editContent("Yum, can you share the recipe?");

    user.displayUserPostsAndComments();

    delete comment1;
    delete comment2;

    return 0;
}
