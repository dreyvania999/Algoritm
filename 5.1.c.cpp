#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int eval(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

int evalMax(const string& expr, int start, int end) {
      vector<vector<int>> maxDP(end + 1, vector<int>(end + 1, INT_MIN));
    vector<vector<int>> minDP(end + 1, vector<int>(end + 1, INT_MAX));

    for (int len = 1; len <= (end - start + 1) / 2 + 1; ++len) {
        for (int i = start; i <= end; i += 2) {
            if (len == 1) {
                maxDP[i][i] = minDP[i][i] = expr[i] - '0';
            }
            else {
                for (int k = 0; k < len - 1; ++k) {
                    for (int j = 0; j < 2; ++j) {
                        int opPos = i + 2 * k + 1;
                        char op = expr[opPos];
                         int leftMax = maxDP[i][i + 2 * k];
                        int rightMax = maxDP[i + 2 * k + 2][end];
                        int leftMin = minDP[i][i + 2 * k];
                        int rightMin = minDP[i + 2 * k + 2][end];

                        int results[] = {
                            eval(leftMax, rightMax, op),
                            eval(leftMax, rightMin, op),
                            eval(leftMin, rightMax, op),
                            eval(leftMin, rightMin, op)
                        };

                        for (int res : results) {
                            maxDP[i][end] = max(maxDP[i][end], res);
                            minDP[i][end] = min(minDP[i][end], res);
                        }
                    }
                }
            }
        }
    }

    return maxDP[start][end];
}

int main() {
    string expression;
    cin >> expression;

    int n = expression.length();
    cout << evalMax(expression, 0, n - 1) << endl;

    return 0;
}