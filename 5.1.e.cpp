#include <iostream>
#include <vector>

std::pair<std::vector<int>, int> pisano(int modulo) {
    std::vector<int> cache{ 0, 1 };
    int cur = 0, next = 1, period = 0;
    int cur_100 = 0, next100 = 1;

    while (true) {
        cur = next;
        next = (cur + next) % modulo;

        cur_100 = next100;
        next100 = (cur_100 + next100) % 100;

        cache.push_back(next100);
        period++;

        if (cur == 0 && next == 1) {
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
    int res = table[a % b_pisano];
    return res;
}

int main() {
    int m, n;
    std::cin >> m >> n;

    int result = (fib(n + 2, 10) - fib(m + 1, 10)) % 10;
    std::cout << result << std::endl;

    return 0;
}
