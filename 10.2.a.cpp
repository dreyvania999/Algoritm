#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;


    std::vector<std::vector<int>> first_graph(n + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<int>> second_graph(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;

        std::vector<int> stops(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> stops[j];
        }

        for (int j = 1; j < k; ++j) {
            int current_stop = stops[j];
            int previous_stop = stops[j - 1];

            first_graph[current_stop][previous_stop] = 1;
            first_graph[previous_stop][current_stop] = 1;
        }


        for (int from = 0; from < k; ++from) {
            for (int to = 0; to < k; ++to) {
                if (from != to) {
                    second_graph[stops[from]][stops[to]] = 1;
                }
            }
        }
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << first_graph[i][j] << (j == n ? "\n" : " ");
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << second_graph[i][j] << (j == n ? "\n" : " ");
        }
    }

    return 0;
}