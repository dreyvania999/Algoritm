#include <iostream>
#include <vector>
#include <algorithm> 


void selectionSort(std::vector<int>& seq) {
        for (size_t i = 0; i < seq.size() - 1; ++i) {
        size_t minIndex = i; 
                for (size_t k = i + 1; k < seq.size(); ++k) {
            if (seq[k] < seq[minIndex]) {
                minIndex = k; 
            }
        }

              std::swap(seq[i], seq[minIndex]);
    }
}

int main() {
    int n;
    std::cin >> n; 
    std::vector<int> a(n); 
        for (int& x : a) {
        std::cin >> x;
    }

     selectionSort(a);

     for (const auto& element : a) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    return 0;
}
