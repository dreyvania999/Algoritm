#include <iostream>
#include <deque>
#include <string>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    std::deque<int> deq;
    std::vector<int> answer;

    for (int i = 0; i < q; ++i) {
        std::string query;
        std::cin >> query;

        if (query == "1") {
            int x;
            std::cin >> x;
            deq.push_back(x);
        }
        else if (query == "2") {
            deq.pop_front();
        }

        if (deq.empty()) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(deq.front());
        }
    }

    for (int ans : answer) {
        std::cout << ans << std::endl;
    }

    return 0;
}