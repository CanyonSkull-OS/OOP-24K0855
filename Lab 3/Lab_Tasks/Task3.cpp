#include <iostream>
using namespace std;


class Library{
    int count = 0;
    string bookList[100];
    string borrowedBooks[100];
    string availableBooks[100];

    
    
    public:
    void initializeLibrary(){
            for (int i = 0; i < 100; i++)
            {
                bookList[i] = "Null";
                availableBooks[i] = "Null";
                borrowedBooks[i] = "Null";
            }
        }

        void addBook(string book){
            bookList[count] = book;
            availableBooks[count] = book;
            count++;
            cout << "Book Added" << endl;
        }

        void lendBook(string book){
            int flag = 0;
            for (int i = 0; i < 100; i++)
            {
                if (availableBooks[i] == book){
                    availableBooks[i] = "Null";
                    borrowedBooks[i] = book;
                    cout << "Book Lended" << endl;
                    flag = 1;
                }
            }
            if (!flag){
                cout << "Book not available" << endl;
            }
        }
        
        int returnBook(string book){
            int flag = 0;
            for (int i = 0; i < 100; i++)
            {
                if (availableBooks[i] == book){
                    cout << "Book already in library" << endl;
                    return 0;
                }
            }
            for (int i = 0; i < 100; i++)
            {
                if (borrowedBooks[i] == book){
                    availableBooks[i] = book;
                    borrowedBooks[i] = "Null";
                    cout << "Book Returned" << endl;
                    flag = 1;
                }
            }
            if (!flag){
                cout << "Book not in DataBase" << endl;
            }
            return 1;
        }
};


int main(){
    Library library1;

    library1.initializeLibrary();

    library1.addBook("Harry Potter");
    library1.addBook("Percy Jackson");

    library1.lendBook("Harry Potter");

    library1.returnBook("Harry Potter");
    library1.returnBook("Harry Poter");

    return 0;
}