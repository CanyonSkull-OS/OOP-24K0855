/*
Omer Shahid
24K-0855
*/

#include <iostream>
using namespace std;


struct Book{
    string title;
    string author;
    int year;
};


Book* createBooks(int n){
    Book* books = new Book[n];
    cout << "Books Created" << endl;
    return books;
}

void populateBooks(Book* books, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details for book " << i+1 << ": " << endl;
        cout << "Title: ";
        cin.ignore();
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].title);
        cout << "Year: ";
        cin >> books[i].year;
        cout << endl;
    }
    
}

void displayBooksAfterSpecificYear(Book* books, int n){
    int year;
    cout << "Enter Year: ";
    cin >> year;
    for (int i = 0; i < n; i++)
    {
        if (books[i].year > year){
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Year: " << books[i].year << endl << endl;
        }
    } 
}


void freeMemory(Book* books){
    delete[] books;
    cout << endl << "Memory has been freed" << endl;
}

int main(){
    int size;
    cout << "Enter number of books: ";
    cin >> size;
    Book* books = createBooks(size);
    populateBooks(books, size);
    displayBooksAfterSpecificYear(books, size);
    freeMemory(books);

    return 0;
}