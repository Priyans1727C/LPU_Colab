#include <iostream>
#include <string>

using namespace std;

class CustomString {
private:
    string str;

public:
    CustomString(string s) {
        str = s;
    }

    void operator++() {
        if (!str.empty()) {
            if (isalpha(str[0])) {
                str[0] = toupper(str[0]);
            }
        }
    }

    string getOriginalString() {
        return str;
    }
};

int main() {
    string input;
    getline(cin, input);

    CustomString customStr(input);

    cout << "Original string: " << customStr.getOriginalString() << endl;

    ++customStr;

    cout << "Modified string: " << customStr.getOriginalString() << endl;

    return 0;
}
