#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
    std::stack<int> stk;
    std::vector<int> answer;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string op;
        std::cin >> op;

        if (op == "1") {
            int x;
            std::cin >> x;
            stk.push(x);
        }
        else if (op == "2") {
            if (!stk.empty()) {
                stk.pop();
            }
        }

        if (stk.empty()) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(stk.top());
        }
    }

    for (auto a : answer) {
        std::cout << a << "\n";
    }

    return 0;
}