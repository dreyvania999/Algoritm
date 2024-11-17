#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> first_data(n);
    for (int i = 0; i < n; ++i) {
        cin >> first_data[i];
    }

    int m;
    cin >> m;
    vector<int> second_data(m);
    for (int i = 0; i < m; ++i) {
        cin >> second_data[i];
    }

    int l;
    cin >> l;
    vector<int> third_data(l);
    for (int i = 0; i < l; ++i) {
        cin >> third_data[i];
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(l + 1)));

    for (int row = 1; row <= n; ++row) {
        for (int seg = 1; seg <= m; ++seg) {
            for (int elem = 1; elem <= l; ++elem) {
                dp[row][seg][elem] = max({ dp[row - 1][seg][elem],
                                          dp[row][seg - 1][elem],
                                          dp[row][seg][elem - 1] });
                if (first_data[row - 1] == second_data[seg - 1] && second_data[seg - 1] == third_data[elem - 1]) {
                    dp[row][seg][elem] = max(dp[row][seg][elem], dp[row - 1][seg - 1][elem - 1] + 1);
                }
            }
        }
    }

    cout << dp[n][m][l] << endl;
    return 0;
}