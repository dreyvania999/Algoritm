#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(const vector<int>& gold, int W, int n) {
       bool dp[W + 1][n + 1];

       for (int i = 0; i <= W; ++i) {
        dp[i][0] = false;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = true;
    }

        for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (gold[i - 1] > w) {
                dp[w][i] = dp[w][i - 1];
            }
            else {
                dp[w][i] = dp[w][i - 1] || dp[w - gold[i - 1]][i - 1];
            }
        }
    }

     for (int w = W; w >= 0; --w) {
        if (dp[w][n]) {
            return w;
        }
    }
    return 0;
}

int main() {
    int W, n;
    cin >> W >> n;

    vector<int> gold(n);
    for (int i = 0; i < n; ++i) {
        cin >> gold[i];
    }

    cout << knapsack(gold, W, n) << endl;
    return 0;
}