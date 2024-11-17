#include <iostream>
#include <vector>

using namespace std;

int partitionLomuto(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }

    int p = partitionLomuto(arr, 0, n - 1);

    for (const auto& x : arr) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}