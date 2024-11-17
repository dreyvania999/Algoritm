#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> countFrequencies(const std::vector<int>& arr) {
    std::unordered_map<int, int> frequencies;
    for (int num : arr) {
        frequencies[num]++;
    }
    return frequencies;
}

bool hasThreeDominantElements(const std::vector<int>& arr, int threshold) {
    std::unordered_map<int, int> frequencies = countFrequencies(arr);

    int dominantCount = 0;
    for (const auto& pair : frequencies) {
        if (pair.second > threshold) {
            dominantCount++;
        }
    }

    return dominantCount == 3;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int threshold = n / 4;
    bool result = hasThreeDominantElements(arr, threshold);

    std::cout << (result ? 1 : 0) << std::endl;

    return 0;
}
