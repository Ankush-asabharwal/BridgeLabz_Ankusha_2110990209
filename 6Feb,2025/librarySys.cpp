instead of all vectors use sturct class for bookName, author Name, Publication Year for all 
and no change other than this in code
#include<iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

void addBooks(vector<string>& bookName, vector<string>& authorName, vector<int>& publicationYear) {
    string bookTitle, authorN;
    int year;

    cin.ignore();
    cout << "Enter the book title : ";
    getline(cin,bookTitle);
    bookName.push_back(bookTitle);

    cout << "Enter the author name : ";
    getline(cin,authorN);
    authorName.push_back(authorN);

    cout << "Enter the publication Year : ";
    cin >> year;
    publicationYear.push_back(year);
}

void deleteBook(vector<string>& bookName , vector<string>& authorName, vector<int>& publicationYear, string name) {
    auto itBook = find(bookName.begin() , bookName.end(), name);
    auto itAuthor = find(authorName.begin() , authorName.end(), name);

    if(itBook != bookName.end()){
        int index = distance(bookName.begin() , itBook);
        bookName.erase(itBook);
        authorName.erase(authorName.begin() + index);
        publicationYear.erase(publicationYear.begin()+index);
        cout << "Book Deleted Successfully" << endl;
    }
    else if(itAuthor != authorName.end()){
        int index = distance(authorName.begin() , itAuthor);
        authorName.erase(itAuthor);
        bookName.erase(bookName.begin() + index);
        publicationYear.erase(publicationYear.begin()+index);
        cout << "Book Deleted Successfully" << endl;
    }
    else{
        cout << "Book not Found" << endl;
    }
}

void display(vector<string>& bookName, vector<string>& authorName, vector<int>& publicationYear){
    if(bookName.empty() && authorName.empty()) {
        cout << "There is no book in Library" << endl;
    }
    for(int i=0;i<bookName.size();i++){
        cout << bookName[i] << " by " << authorName[i] << ", " << publicationYear[i] << endl;
    }
}

void searchByBookName(vector<string> bookName, string BookName) {
    for(int i=0; i<bookName.size(); i++){
        if(bookName[i]==BookName){
            cout << bookName[i] << " Book Found!" << endl;
            return;
        }
    }
    cout << "Book Not Found!" << endl;
}

void searchByAuthorName(vector<string> authorName, string AuthorName){
    for(int i=0;i<authorName.size();i++){
        if(authorName[i]==AuthorName){
            cout << "Book Found!" << endl;
            return;
        }
    }
    cout << "Book Not Found!" << endl;
}

void sortBooksByYear(vector<string>& bookName, vector<string>& authorName, vector<int>& publicationYear) {
    int n = publicationYear.size();
    
    // Selection Sort Approach
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (publicationYear[j] < publicationYear[minIndex]) {
                minIndex = j;
            }
        }
        swap(publicationYear[i], publicationYear[minIndex]);
        swap(bookName[i], bookName[minIndex]);
        swap(authorName[i], authorName[minIndex]);
    }
}

void borrowedBooks(vector<string>& borrowBooks, vector<string>& bookName, vector<string>& authorName, vector<int>& publicationYear){
    string bookN;
    cout << "Enter the name of the book you want to borrow : ";
    getline(cin, bookN);
    for(int i=0;i<bookName.size();i++){
        if(bookName[i]==bookN){
            borrowBooks.push_back(bookN);
            bookName.erase(bookName.begin()+i);
            authorName.erase(authorName.begin()+i);
            publicationYear.erase(publicationYear.begin()+i);
            cout << "Book successfully borrowed!" << endl;
        }
        cout << "Book not found or already borrowed!" << endl;
    }
}

void returnBook(vector<string>& borrowBooks, vector<string>& bookName, vector<string>& authorName, vector<int>& publicationYear) {
    string bookN;
    cout << "Enter the book name you want to return : ";
    getline(cin, bookN);
    
}

int main() {
    vector<string> bookName;
    vector<string> authorName;
    vector<int> publicationYear;

    vector<string> borrowBooks;

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
    cout << "8. Exit" << endl;

    string name;
    string BookName;
    string AuthorName;
    cin >> num;
    cin.ignore();

    switch(num){
        case 1: 
            addBooks(bookName,authorName,publicationYear);
            break;
        case 2:
            cout << "Enter the name of book or author name to delete : ";
            cin >> name;
            deleteBook(bookName,authorName,publicationYear,name);
            break;
        case 3:
            cout << "Enter the Book Name : " ;
            cin >> BookName;
            searchByBookName(bookName,BookName);
            break;
        case 4:
            cout << "Enter the Author Name : ";
            cin >> AuthorName;
            searchByAuthorName(authorName, AuthorName);
            break;
        case 5:
            display(bookName,authorName,publicationYear);
            break;
        case 6:
            sortBooksByYear(bookName,authorName,publicationYear);
            break;
        case 7:
            borrowedBooks(borrowBooks, bookName, authorName, publicationYear);
        case 8:
            cout << "Exiting...";
            break;
    }
    }while(num != 8);

    return 0;
}