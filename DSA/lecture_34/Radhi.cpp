
#include <iostream>
using namespace std;

int main() {
    int data, ans = 0;
    while (1) {
        cin >> data;
        if (data == -1) {
            break;
        }
        ans += data;
    }
    cout << ans; // Output the accumulated sum
    return 0;
}
