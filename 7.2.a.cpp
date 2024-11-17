#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& a) {
    int candidate = 0;
    int count = 0;

    for (int person : a) {
        if (count == 0) {
            candidate = person;
            count++;
        }
        else if (person == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return (count > 0 ? 1 : 0);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ax(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ax[i];
    }

    std::cout << majorityElement(ax) << std::endl;

    return 0;
}
