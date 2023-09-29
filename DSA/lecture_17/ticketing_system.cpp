#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    int ticketQueue[N];
    
    for (int i = 0; i < N; i++) {
        cin >> ticketQueue[i];
    }
    
    reverseArray(ticketQueue, 0, K - 1);

    for (int i = 0; i < N; i++) {
        cout << ticketQueue[i] << " ";
    }
    
    return 0;
}
