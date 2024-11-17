#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> random_quick_sort(size_t len_a, vector<int>& arr) {
    if (len_a <= 1) {
        return arr;
    }

    srand(time(nullptr));  
    int random_index = rand() % len_a;
    int random_element = arr[random_index];

    vector<int> arr_small, arr_equal, arr_big;
    for (int num : arr) {
        if (num < random_element) {
            arr_small.push_back(num);
        }
        else if (num == random_element) {
            arr_equal.push_back(num);
        }
        else {
            arr_big.push_back(num);
        }
    }

    vector<int> sort_arr_small = random_quick_sort(arr_small.size(), arr_small);
    vector<int> sort_arr_big = random_quick_sort(arr_big.size(), arr_big);

    vector<int> final(sort_arr_small);
    final.insert(final.end(), arr_equal.begin(), arr_equal.end());
    final.insert(final.end(), sort_arr_big.begin(), sort_arr_big.end());

    return final;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_array = random_quick_sort(a.size(), a);
    for (int num : sorted_array) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}