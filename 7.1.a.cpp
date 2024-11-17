#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, const int& query) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == query) {
            return mid;
        }
        else if (arr[mid] < query) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> k[i];
    }

    int q;
    std::cin >> q;

    std::cout << binarySearch(k, q) << std::endl;

    return 0;
}
