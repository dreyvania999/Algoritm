#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int l = left; l <= right; ++l) {
        arr[l] = temp[l];
    }
}

void mergeSort(vector<int>& arr, int left, int right, vector<int>& temp) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, temp);

        mergeSort(arr, mid + 1, right, temp);

        merge(arr, left, mid, right, temp);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }

    vector<int> temp(n); 
    mergeSort(arr, 0, n - 1, temp);

    for (const auto& x : arr) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
