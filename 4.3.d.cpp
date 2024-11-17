#include <iostream>
#include <vector>
#include <algorithm>

int main() {
        int n;
    std::cin >> n;

        std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

        std::sort(arr.begin(), arr.end());

       long long right_product = static_cast<long long>(arr[n - 2]) * arr[n - 1] * arr[n - 3] * arr[n - 4];
    long long left_product = static_cast<long long>(arr[0]) * arr[1] * arr[n - 1] * arr[n - 2];
    long long full_left_product = static_cast<long long>(arr[0]) * arr[1] * arr[2] * arr[3];

        std::cout << std::max({ right_product, left_product, full_left_product }) << std::endl;

    return 0;
}
