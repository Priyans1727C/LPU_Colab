// You are using GCC
#include <iostream>
using namespace std;

int main() {
    int n, m;

    
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    
    int max_size = max(n, m);
    int result[max_size];
    for (int i = 0; i < max_size; i++) {
        int val1 = (i < n) ? arr1[i] : 0;
        int val2 = (i < m) ? arr2[i] : 0;
        result[i] = val1 + val2;
    }

  
    for (int i = 0; i < max_size; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}