#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& gold, int n) {
    int totalSum = accumulate(gold.begin(), gold.end(), 0);
    if (totalSum % 3 != 0) {
        return false;
    }
    int target = totalSum / 3;
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(target + 1, vector<bool>(target + 1, false)));
    dp[0][0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int s1 = 0; s1 <= target; ++s1) {
            for (int s2 = 0; s2 <= target; ++s2) {
                dp[i][s1][s2] = dp[i - 1][s1][s2];
                if (s1 >= gold[i]) {
                    dp[i][s1][s2] = dp[i][s1][s2] || dp[i - 1][s1 - gold[i]][s2];
                }
                if (s2 >= gold[i]) {
                    dp[i][s1][s2] = dp[i][s1][s2] || dp[i - 1][s1][s2 - gold[i]];
                }
            }
        }
    }
    return dp[n][target][target];
}

int main() {
    int n;
    cin >> n;
    vector<int> gold(n + 1); 
    for (int i = 1; i <= n; ++i) {
        cin >> gold[i];
    }
    cout << (canPartition(gold, n) ? 1 : 0) << endl;
    return 0;
}