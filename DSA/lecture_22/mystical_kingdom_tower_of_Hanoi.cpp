#include <iostream>
using namespace std;

int towerOfHanoi(int n) {
    if (n == 1) {
        return 1;
    } else {
        int move1 = towerOfHanoi(n - 1);
        

        int move2 = towerOfHanoi(n - 1);
        
        return move1 + move2 + 1;
    }
}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = towerOfHanoi(n);
    cout<< totalMoves << endl;
    
    return 0;
}
