#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    int publicationYear;
};

void addBooks(vector<Book>& books) {
    Book newBook;
    cin.ignore();
    cout << "Enter the book title: ";
    getline(cin, newBook.title);
    
    cout << "Enter the author name: ";
    getline(cin, newBook.author);
    
    cout << "Enter the publication year: ";
    cin >> newBook.publicationYear;
    
    books.push_back(newBook);
}

void deleteBook(vector<Book>& books, string name) {
    for(auto i=books.begin(); i!=books.end();i++){
        if(i->title == name || i->author == name) {
            books.erase(i);
            cout << "Book delete successfully" << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}

void display(const vector<Book>& books) {
    if (books.empty()) {
        cout << "There is no book in the Library" << endl;
        return;
    }
    for (auto i =books.begin();i<books.end();i++) {
        cout << i->title << " by " << i->author << ", " << i->publicationYear << endl;
    }
}

void searchByBookName(const vector<Book>& books, string bookName) {
    for (const auto& book : books) {
        if (book.title == bookName) {
            cout << book.title << " Book Found!" << endl;
            return;
        }
    }
    cout << "Book Not Found!" << endl;
}

void searchByAuthorName(const vector<Book>& books, string authorName) {
    for (const auto& book : books) {
        if (book.author == authorName) {
            cout << "Book Found!" << endl;
            return;
        }
    }
    cout << "Book Not Found!" << endl;
}

void sortBooksByYear(vector<Book>& books) {
    int n = books.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(books[i].publicationYear > books[j].publicationYear){
                swap(books[i], books[j]);
            }
        }
    }
}

void borrowedBooks(vector<Book>& borrowed, vector<Book>& books) {
    string bookN;
    cout << "Enter the name of the book you want to borrow: ";
    cin.ignore();
    getline(cin, bookN);

    for(int i = 0;i<books.size();i++){
        if(books[i].title == bookN){
            borrowed.push_back(books[i]);
            books.erase(books.begin() + i);
            cout << "Book successfully borrowed!" << endl;
            return;
        }
    }
    cout << "Book not found or already borrowed!" << endl;
}

void returnBook(vector<Book>& books, vector<Book>& borrowed) {
    string bookN;
    cout << "Enter the name of the book you want to return: ";
    cin.ignore();
    getline(cin, bookN);

    for(int i = 0;i<borrowed.size();i++){
        if(borrowed[i].title == bookN) {
            books.push_back(borrowed[i]);
            borrowed.erase(borrowed.begin()+i);
            cout << "Book return" << endl;
            return;
        }
    }
    cout << "Book Not found" << endl;
}

int main() {
    vector<Book> books;
    vector<Book> borrowedBooksList;

    int num;
    do {
        cout << "Choose from the Menu :- " << endl;
        cout << "1. Add Books" << endl;
        cout << "2. Delete Book" << endl;
        cout << "3. Search book by Book Name" << endl;
        cout << "4. Search book by Author Name" << endl;
        cout << "5. Display all the books" << endl;
        cout << "6. Sort the books by publication year" << endl;
        cout << "7. Borrow book" << endl;
        cout << "8. Return Book" << endl;
        cout << "9. Exit" << endl;
        
        string name, bookName, authorName;
        cin >> num;
        cin.ignore();

        switch (num) {
            case 1:
                addBooks(books);
                break;
            case 2:
                cout << "Enter the name of book or author name to delete: ";
                getline(cin, name);
                deleteBook(books, name);
                break;
            case 3:
                cout << "Enter the Book Name: ";
                getline(cin, bookName);
                searchByBookName(books, bookName);
                break;
            case 4:
                cout << "Enter the Author Name: ";
                getline(cin, authorName);
                searchByAuthorName(books, authorName);
                break;
            case 5:
                display(books);
                break;
            case 6:
                sortBooksByYear(books);
                break;
            case 7:
                borrowedBooks(borrowedBooksList, books);
                break;
            case 8:
                returnBook(books, borrowedBooksList);
                break;
            case 9:
                cout << "Exiting...";
                break;
        }
    } while (num != 9);

    return 0;
}
