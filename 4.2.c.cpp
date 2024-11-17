#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    // ���������� ������ ����� ������ ����� ����� n
    std::cin.ignore();

    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    if (a.size() != n || b.size() != n) {
        std::cerr << "������ ������ ���� ���������� �����!" << std::endl;
        return 1;
    }

    std::string result;
    for (int i = 0; i < n; ++i) {
        result += a[i];
        result += b[i];
    }

    std::cout << result << std::endl;

    return 0;
}
