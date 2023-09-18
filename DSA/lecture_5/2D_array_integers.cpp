// You are using GCC
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) {
        return 0;
    }

    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    int n = envelopes.size();
    vector<int> dp(n, 1);

    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i][1] > envelopes[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> envelopes(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> envelopes[i][0] >> envelopes[i][1];
    }

    int result = maxEnvelopes(envelopes);
    cout << result << endl;

    return 0;
}
