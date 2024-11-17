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

    vector<vector<int>> table(n + 1, vector<int>(m + 1));

    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= m; ++col) {
            table[row][col] = max(table[row - 1][col], table[row][col - 1]);
            if (first_data[row - 1] == second_data[col - 1]) {
                table[row][col] = max(table[row][col], table[row - 1][col - 1] + 1);
            }
        }
    }

    cout << table[n][m] << endl;
    return 0;
}
