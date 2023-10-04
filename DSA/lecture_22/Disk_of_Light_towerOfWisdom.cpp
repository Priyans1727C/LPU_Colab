#include <iostream>
using namespace std;

int towerOfWisdom(int n, char source, char auxiliary, char illuminated) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << illuminated << endl;
        return 1;
    } else {
        int move1 = towerOfWisdom(n - 1, source, illuminated, auxiliary);
        
        cout << "Move disk " << n << " from " << source << " to " << illuminated << endl;
        
        int move2 = towerOfWisdom(n - 1, auxiliary, source, illuminated);
        
        return move1 + move2 + 1;
    }
}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = towerOfWisdom(n, 'A', 'B', 'C');
    cout << "Total number of times the disk is moved: " << totalMoves << endl;
    
    return 0;
}
