#include <iostream>
#include <vector>

std::pair<std::vector<int>, int> pisano(int modulo) {
    std::vector<int> cache{ 0, 1 };
    int cur = 0, next_val = 1, period = 0;

    while (true) {
        int temp = (cur + next_val) % modulo;
        cache.push_back(temp);
        cur = next_val;
        next_val = temp;
        period++;

        if (cur == 0 && next_val == 1) {
            break;
        }
    }

    return { cache, period };
}

int fib(int a, int b) {
    if (a <= 1) {
        return a;
    }

    auto [table, b_pisano] = pisano(b);
    int result = table[a % b_pisano];
    return (result > 0 ? result : 10) - 1;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib(n + 2, 10) << std::endl;
    return 0;
}
