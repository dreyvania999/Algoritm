#include <iostream>
#include <cmath>

int t(int T) {
    if (T == 1) {
        return 1;
    }
    else {
        return 2 * t(T - 1) + 1;
    }
}

int big_t(int m) {
    int k = m - static_cast<int>(round(sqrt(2 * m + 1))) + 1;

    if (m == 1) {
        return 1;
    }
    else {
        return 2 * big_t(k) + t(m - k);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << big_t(n) << std::endl;
    return 0;
}