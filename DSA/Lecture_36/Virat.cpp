
#include <iostream>
using namespace std;

#define MAX_N 100

int findInfluentialIndividual(int (&acquaintances)[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; ++i) {
        int followers = 0;
        int following = 0;

        for (int j = 0; j < n; ++j) {
            followers += acquaintances[j][i];
            following += acquaintances[i][j];
        }

        if (followers > following) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int acquaintances[MAX_N][MAX_N] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> acquaintances[i][j];
        }
    }

    int influentialIndividualIndex = findInfluentialIndividual(acquaintances, n);
    if (influentialIndividualIndex != -1) {
        cout << "Influential Individual: " << influentialIndividualIndex;
    } else {
        cout << "There is no influential individual in the group";
    }

    return 0;
}
