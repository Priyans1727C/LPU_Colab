#include <iostream>
#include <cstring>

using namespace std;

class CustomString {
private:
    char str[101]; 

public:
    CustomString(char s[]) {
        strcpy(str, s);
    }

    void operator!() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (isalpha(str[i])) {
                if (islower(str[i])) {
                    str[i] = toupper(str[i]);
                } else {
                    str[i] = tolower(str[i]);
                }
            }
        }
    }

    char* getOriginalString() {
        return str;
    }
};

int main() {
    char input[101];
    cin.getline(input, sizeof(input));

    CustomString customStr(input);

    cout << "Original String: " << customStr.getOriginalString() << endl;

    !customStr;

    cout << "Inverted String: " << customStr.getOriginalString() << endl;

    return 0;
}
