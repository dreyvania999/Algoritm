#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
        int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m + 1);
    for (int i = 0; i <= m; ++i) {
        cin >> b[i];
    }

       int k = max(n, m);

       vector<int> c(k + 1);

        for (int i = 0; i <= k; ++i) {
        if (i <= n) {
            c[i] += a[n - i];
        }
        if (i <= m) {
            c[i] += b[m - i];
        }
    }


    cout << k << endl;
    for (int i = k; i >= 0; --i) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}