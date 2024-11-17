#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i];
    }

    vector<int> answer(n, 0);
    stack<pair<int, int>> stk;

    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && queries[i] > stk.top().first) {
            pair<int, int> top = stk.top();
            stk.pop();
            answer[i] += answer[top.second] + 1;
        }
        stk.push({ queries[i], i });
    }

    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}