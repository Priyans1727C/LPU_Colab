// You are using GCC
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int n, m;

    cin >> n;
    cin.ignore();

    vector<string> fictionBooks;
    for (int i = 0; i < n; i++) {
        string title;
        getline(cin, title);
        fictionBooks.push_back(title);
    }

    cin >> m;
    cin.ignore();

    vector<string> nonFictionBooks;
    for (int i = 0; i < m; i++) {
        string title;
        getline(cin, title);
        nonFictionBooks.push_back(title);
    }

    cout << "Catalog:" << endl;
    for (const string& title : fictionBooks) {
        cout << title << endl;
    }
    for (const string& title : nonFictionBooks) {
        cout << title << endl;
    }

    return 0;
}
