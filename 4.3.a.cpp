#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    if (n < 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int first_max = -1;
    int second_max = -1;

    for (const int& num : sequence) {
        if (num > first_max) {
            second_max = first_max;
            first_max = num;
        }
        else if (num > second_max && num != first_max) {
            second_max = num;
        }
    }

    std::cout << first_max * second_max << std::endl;

    return 0;
}
