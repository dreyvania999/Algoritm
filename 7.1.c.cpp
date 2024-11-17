#include <iostream>
#include <vector>

std::vector<int> countOccurrences(const std::vector<int>& arr_k, const std::vector<int>& arr_q) {
    std::vector<int> result(arr_q.size());

    for (size_t i = 0; i < arr_q.size(); ++i) {
        int target = arr_q[i];
        int low = 0;
        int high = static_cast<int>(arr_k.size()) - 1;
        int first_occurrence = -1;

        // Найти первое вхождение числа
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr_k[mid] == target) {
                first_occurrence = mid;
                high = mid - 1;
            }
            else if (arr_k[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (first_occurrence == -1) {
            result[i] = 0;
            continue;
        }

        // Найти последнее вхождение числа
        low = first_occurrence;
        high = static_cast<int>(arr_k.size()) - 1;
        int last_occurrence = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr_k[mid] == target) {
                last_occurrence = mid;
                low = mid + 1;
            }
            else if (arr_k[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        result[i] = last_occurrence - first_occurrence + 1;
    }

    return result;
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

    std::vector<int> result = countOccurrences(k, q);

    for (const auto& r : result) {
        std::cout << r << ' ';
    }

    return 0;
}
