#include <iostream>
using namespace std;

int lastDigitFibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

      int prev = 0, curr = 1;

    for (int i = 2; i <= n; ++i) {
        int next = (prev + curr) % 10;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    int n;
    cin >> n;
    cout << lastDigitFibonacci(n) << endl;
    return 0;
}