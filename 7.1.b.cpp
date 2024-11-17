#include <iostream>
#include <vector>

std::vector<int> manyBinarySearches(const std::vector<int>& arr, const std::vector<int>& queries) {
    std::vector<int> results;

    for (const auto& query : queries) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;
        int index = -1;

        while (right >= left) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == query) {
                index = mid;
                break;
            }
            else if (arr[mid] > query) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        results.push_back(index);
    }

    return results;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> k[i];
    }

    int m;
    std::cin >> m;

    std::vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> q[i];
    }

    std::vector<int> results = manyBinarySearches(k, q);

    for (const auto& result : results) {
        std::cout << result << "\n";
    }

    return 0;
}
