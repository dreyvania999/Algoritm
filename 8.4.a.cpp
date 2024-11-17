#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  

int main() {
    std::string word_one, word_two;

        std::cin >> word_one;
    std::cin >> word_two;

       word_one = 'x' + word_one;
    word_two = 'x' + word_two;

    int m = word_one.length();
    int n = word_two.length();

        std::vector<std::vector<int>> table(m, std::vector<int>(n));

        for (int i = 0; i < m; ++i) {
        table[i][0] = i;
    }
    for (int j = 0; j < n; ++j) {
        table[0][j] = j;
    }

        for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            int match = table[i - 1][j - 1];
            int mismatch = table[i - 1][j - 1] + 1;
            int insertion = table[i][j - 1] + 1;
            int deletion = table[i - 1][j] + 1;

            if (word_one[i] == word_two[j]) {
                table[i][j] = std::min({ match, insertion, deletion });  // Используем правильный вызов std::min
            }
            else {
                table[i][j] = std::min({ mismatch, insertion, deletion });  // Используем правильный вызов std::min
            }
        }
    }

       std::cout << table[m - 1][n - 1] << std::endl;

    return 0;
}