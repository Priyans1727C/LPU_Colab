// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < arr[mid + 1]) {
         
            left = mid + 1;
        } else {
            
            right = mid;
        }
    }
    
    return arr[left];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int peak = findPeakElement(arr);
    cout << peak << endl;
    
    return 0;
}
