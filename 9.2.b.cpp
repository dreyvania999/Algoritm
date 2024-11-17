#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>


int count_interesting_pairs(const std::vector<std::string>& words) {
    std::unordered_map<std::string, std::set<int>> mask_map;
    int pair_count = 0;

    for (int i = 0; i < words.size(); ++i) {
        const std::string& word = words[i];

        for (int pos = 0; pos < word.length(); ++pos) {
            std::string mask = word;
            mask[pos] = '*';

            auto it = mask_map.find(mask);
            if (it != mask_map.end()) {
                                for (const int j : it->second) {
                    if (j != i && word != words[j]) {
                        pair_count++;
                    }
                }

                               it->second.insert(i);
            }
            else {
                                std::set<int> indices;
                indices.insert(i);
                mask_map[mask] = std::move(indices);
            }
        }
    }

    return pair_count;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    std::cout << count_interesting_pairs(words) << std::endl;

    return 0;
}