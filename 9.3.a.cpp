#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<std::string, std::string> unknown_dict;
    std::vector<std::string> answer;

    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "1") {
            std::string key, value;
            std::cin >> key >> value;
            unknown_dict[key] = value;
        }
        else if (command == "2") {
            std::string key;
            std::cin >> key;

            auto it = unknown_dict.find(key);
            if (it != unknown_dict.end()) {
                answer.push_back(it->second);
            }
            else {
                answer.push_back("-1");
            }
        }
    }

    for (const auto& ans : answer) {
        std::cout << ans << '\n';
    }

    return 0;
}