#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

        int min_element = 0;
    int max_element = 1;
    int min_not_approved = 0;

    for (int num = 2; num < n; ++num) {
        if (arr[num] > arr[max_element] || (arr[num] - arr[min_not_approved] > arr[max_element] - arr[min_element])) {
            if (arr[max_element] < arr[min_element]) {
                min_element = max_element;
            }

            if (arr[min_element] > arr[min_not_approved]) {
                min_element = min_not_approved;
            }
            max_element = num;
        }
        else if (arr[num] < arr[min_element] && arr[num] < arr[min_not_approved]) {
            min_not_approved = num;
        }
    }

    std::cout << min_element + 1 << ' ' << max_element + 1 << '\n';


    min_element = 1;
    max_element = 0;
    int max_not_approved = 0;

    for (int num = 2; num < n; ++num) {
        if (arr[num] < arr[min_element] || (arr[max_not_approved] - arr[num] > arr[max_element] - arr[min_element])) {
            if (arr[min_element] > arr[max_element]) {
                max_element = min_element;
            }

            if (arr[max_element] < arr[max_not_approved]) {
                max_element = max_not_approved;
            }
            min_element = num;
        }
        else if (arr[num] > arr[max_element] && arr[num] > arr[max_not_approved]) {
            max_not_approved = num;
        }
    }

    std::cout << max_element + 1 << ' ' << min_element + 1 << '\n';

    return 0;
}