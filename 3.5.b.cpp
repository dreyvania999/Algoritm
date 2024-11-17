#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

        std::vector<int> mergedSequence;

    for (int i = 0; i < n; ++i) {
        int mi;
        std::cin >> mi;

               std::vector<int> currentSequence(mi);
        for (int j = 0; j < mi; ++j) {
            std::cin >> currentSequence[j];
        }

                mergedSequence.insert(mergedSequence.end(), currentSequence.begin(), currentSequence.end());
    }

       std::sort(mergedSequence.begin(), mergedSequence.end());

        for (const auto& num : mergedSequence) {
        std::cout << num << ' ';
    }

    return 0;
}
