#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int medianOfThree(vector<int>& arr, int low, int mid, int high) {
    if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) ||
        (arr[high] <= arr[mid] && arr[mid] <= arr[low]))
        return mid;
    else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) ||
        (arr[high] <= arr[low] && arr[low] <= arr[mid]))
        return low;
    else
        return high;
}

int partition(vector<int>& arr, int low, int high) {
        int mid = low + (high - low) / 2;
    int pivotIndex = medianOfThree(arr, low, mid, high);
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void QuickSort(vector<int>& arr, int low, int high) {
    const int cutoff = 10; 
    if (high - low + 1 <= cutoff) {
        insertionSort(arr, low, high);
    }
    else {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }

    QuickSort(arr, 0, n - 1);

    for (const auto& x : arr) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}