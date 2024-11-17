#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    std::set<std::string> numbers;
    std::vector<std::string> answer;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        char query;
        std::string num;
        std::cin >> query >> num;

        if (query == '1') {
            numbers.insert(num);
        }
        else if (query == '2') {
            if (numbers.find(num) != numbers.end()) {
                answer.push_back("1");
            }
            else {
                answer.push_back("0");
            }
        }
    }

    for (const auto& result : answer) {
        std::cout << result << "\n";
    }

    return 0;
}