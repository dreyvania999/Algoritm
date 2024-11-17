#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>, int> merge(vector<int>& left_half, vector<int>& right_half) {
    vector<int> sorted_list;
    int inversions = 0;

    while (!left_half.empty() && !right_half.empty()) {
        if (left_half.front() <= right_half.front()) {
            sorted_list.push_back(left_half.front());
            left_half.erase(left_half.begin());
        }
        else {
            sorted_list.push_back(right_half.front());
            right_half.erase(right_half.begin());
            inversions += left_half.size();
        }
    }

    sorted_list.insert(sorted_list.end(), left_half.begin(), left_half.end());
    sorted_list.insert(sorted_list.end(), right_half.begin(), right_half.end());

    return make_pair(sorted_list, inversions);
}

pair<vector<int>, int> count_inversions(int n, vector<int>& a) {
    if (n <= 1) {
        return make_pair(a, 0);
    }

    int pivot = n / 2;
    vector<int> left_half(a.begin(), a.begin() + pivot);
    vector<int> right_half(a.begin() + pivot, a.end());

    auto left_result = count_inversions(pivot, left_half);
    auto right_result = count_inversions(n - pivot, right_half);

    auto merged_result = merge(left_result.first, right_result.first);
    return make_pair(merged_result.first, left_result.second + right_result.second + merged_result.second);
}

int main() {
    int n;
    cin >> n;

    vector<int> list_a(n);
    for (int i = 0; i < n; ++i) {
        cin >> list_a[i];
    }

    cout << count_inversions(n, list_a).second << endl;

    return 0;
}