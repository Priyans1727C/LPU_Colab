#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> firstList(n);
    for (int i = 0; i < n; ++i) {
        cin >> firstList[i];
    }

    cin >> m;
    vector<int> secondList(m);
    for (int i = 0; i < m; ++i) {
        cin >> secondList[i];
    }

    vector<int> mergedList;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (firstList[i] < secondList[j]) {
            if (i == 0 || firstList[i] != firstList[i - 1]) {
                mergedList.push_back(firstList[i]);
            }
            i++;
        } else if (secondList[j] < firstList[i]) {
            if (j == 0 || secondList[j] != secondList[j - 1]) {
                mergedList.push_back(secondList[j]);
            }
            j++;
        } else {
            if (i == 0 || firstList[i] != firstList[i - 1]) {
                mergedList.push_back(firstList[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n) {
        if (i == 0 || firstList[i] != firstList[i - 1]) {
            mergedList.push_back(firstList[i]);
        }
        i++;
    }

    while (j < m) {
        if (j == 0 || secondList[j] != secondList[j - 1]) {
            mergedList.push_back(secondList[j]);
        }
        j++;
    }

    for (int k = 0; k < mergedList.size(); ++k) {
        cout << mergedList[k];
        if (k < mergedList.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
