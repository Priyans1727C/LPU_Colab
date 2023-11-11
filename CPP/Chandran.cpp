#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_BOOKS = 20;

void addBook(vector<string>& books, const string& bookID) {
    if (books.size() >= MAX_BOOKS) {
        throw runtime_error("Maximum number of books reached.");
    }

    books.push_back(bookID);
    cout << "Book with ID " << bookID << " added to the library." << endl;
}

void borrowBook(vector<string>& books, const string& bookID) {
    auto it = find(books.begin(), books.end(), bookID);
    if (it == books.end()) {
        throw runtime_error("Invalid book ID.");
    }

    books.erase(it);
    cout << "Book with ID " << bookID << " borrowed successfully." << endl;
}

void returnBook(vector<string>& books, const string& bookID) {
    if (books.size() >= MAX_BOOKS) {
        throw runtime_error("Maximum number of books reached.");
    }

    books.push_back(bookID);
    cout << "Book with ID " << bookID << " returned to the library." << endl;
}

int main() {
    vector<string> books;

    try {
        int numBooks;
        cin >> numBooks;

        for (int i = 0; i < numBooks; ++i) {
            string bookID;
            cin >> bookID;
            addBook(books, bookID);
        }

        string borrowID, returnID;
        cin >> borrowID >> returnID;

        borrowBook(books, borrowID);
        returnBook(books, returnID);

    } catch (const exception& e) {
        cout << "Exception caught. Error: " << e.what() << endl;
    }

    return 0;
}
