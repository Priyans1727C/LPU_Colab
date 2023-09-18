// You are using GCC
#include <iostream>
#include <vector>

using namespace std;

int findMinimum(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    
    return nums[left];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int minimum = findMinimum(nums);
    cout << minimum << endl;
    
    return 0;
}
