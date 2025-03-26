#include <iostream>
using namespace std;

class Book{
    int BookID;
    string Title;
    string Author;
    bool AvailStatus;

    public:
        Book(){}

        void setBookDetails(int id, string t, string a){
            BookID = id;
            Title = t;
            Author = a;
            AvailStatus = true;
        }

        void DisplayBookDetails(){
            cout << "ID: " << BookID << endl;
            cout << "Title: " << Title << endl;
            cout << "Author: " << Author << endl;
            cout << "Availability Status: " << AvailStatus << endl;
        }

        int getBookID(){return BookID;}

        void toggleAvailability(){
            if(AvailStatus) AvailStatus = false;
            else AvailStatus = true;
        }

};


class Library{
    int bookCount;
    Book books[10];
    public:
        Library() : bookCount(0){}

        void addBook(Book book){
            if (bookCount > 10)
            {
                cout << "Get a life" << endl;
            }
            else{
                books[bookCount++] = book;
                cout << "Book Added" << endl;
            }
            
        }

        void DisplayAllBooks(){
            for (int i = 0; i < bookCount; i++)
            {
                books[i].DisplayBookDetails();
            }
            
        }

        Book* findBook(int id){
            for (int i = 0; i < bookCount; i++)
            {
                if(id == books[i].getBookID()){
                    return &books[i];
                }
            }
            return nullptr;
        }
};

int main(){
    Library lib1;

    Book b1;
    Book b2;
    Book b3;

    b1.setBookDetails(1, "Why Fatima is white", "Omer Shahid");
    b2.setBookDetails(2, "Why Fatima is black", "Omer Shahid");
    b3.setBookDetails(3, "Why Fatima is a simpson", "Omer Shahid");

    lib1.addBook(b1);
    lib1.addBook(b2);
    lib1.addBook(b3);

    lib1.DisplayAllBooks();

    Book* foundBook = lib1.findBook(2);
    if(foundBook){
        foundBook->DisplayBookDetails();
        foundBook->toggleAvailability();
        cout << endl;
        foundBook->DisplayBookDetails();
    }
    else{
        cout << "Book does not exist" << endl;
    }
}

