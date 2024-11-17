#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Stack {
public:
    void push(int item) {
        array.push_back(item);
    }

    int pop() {
        int item = array.back();
        array.pop_back();
        return item;
    }

    bool empty() const {
        return array.empty();
    }

    int back() const {
        return array.back();
    }

private:
    vector<int> array;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i];
    }

    Stack arr;
    Stack temp_arr;
    int inf = 3 * 100000 + 1;

    long long answer = 0;
    int temp_min = inf;

    for (int i = 0; i < k; ++i) {
        temp_arr.push(queries[i]);
        if (temp_min > queries[i]) {
            temp_min = queries[i];
        }
    }
    answer += temp_min;
    temp_min = inf;

    for (int i = k; i < n; ++i) {
        if (arr.empty()) {
            int cur_min = inf;
            while (!temp_arr.empty()) {
                if (cur_min > temp_arr.back()) {
                    cur_min = temp_arr.back();
                }
                arr.push(cur_min);
                temp_arr.pop();
            }
            temp_min = inf;
        }
        arr.pop();

        temp_arr.push(queries[i]);
        if (temp_min > queries[i]) {
            temp_min = queries[i];
        }

        int res = temp_min;
        if (!arr.empty()) {
            res = min(res, arr.back());
        }
        answer += res;
    }

    cout << answer << endl;

    return 0;
}