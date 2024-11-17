#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool canCoverPoints(const vector<int>& points, int length, int segments) {
    int currentSegmentEnd = points[0] + length;
    segments--;
    for (int i = 1; i < points.size(); ++i) {
        if (currentSegmentEnd < points[i]) {
            if (segments == 0) {
                return false;
            }
            currentSegmentEnd = points[i] + length;
            segments--;
        }
    }
    return true;
}

int findMinLength(int n, const vector<int>& points, int k) {
    if (k >= points.size()) {
        return 0;
    }
    int minLength = 0;
    int maxLength = points.back() - points.front();
    while (minLength != maxLength) {
        int mid = minLength + (maxLength - minLength) / 2;
        if (mid == maxLength || mid == minLength) {
            return maxLength;
        }
        if (canCoverPoints(points, mid, k)) {
            maxLength = mid;
        }
        else {
            minLength = mid + 1;
        }
    }
    return maxLength;
}

int main() {
    int n, k;
    cin >> n >> k;

    set<int> uniquePoints;
    for (int i = 0; i < n; ++i) {
        int point;
        cin >> point;
        uniquePoints.insert(point);
    }

    vector<int> points(uniquePoints.begin(), uniquePoints.end());

    cout << findMinLength(n, points, k) << endl;

    return 0;
}
