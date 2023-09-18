#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int findMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int low = matrix[0][0];
    int high = matrix[rows - 1][cols - 1];
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        
        if (count <= (rows * cols) / 2) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int median = findMedian(matrix);
    cout << median << endl;
    
    return 0;
}
