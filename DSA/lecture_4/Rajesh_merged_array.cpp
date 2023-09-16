// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> array1(n);
    for (int i = 0; i < n; ++i) {
        cin >> array1[i];
    }

    cin >> m;
    vector<int> array2(m);
    for (int i = 0; i < m; ++i) {
        cin >> array2[i];
    }

    vector<int> result(max(n, m));
    for (int i = 0; i < max(n, m); ++i) {
        result[i] = (i < n ? array1[i] : 0) + (i < m ? array2[i] : 0);
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
