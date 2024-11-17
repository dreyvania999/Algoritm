#include <iostream>

int main() {
    int n;

    std::cin >> n;

    if (1 + ((n - 2) * 2) > (1.5 * n)) {
        std::cout << "Yes\n";
        std::cout << n << ' ';
        for (int i = 1; i <= n - 1; ++i) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    else {
        std::cout << "No\n";
    }

    return 0;
}
