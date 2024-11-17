#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    sort(nums.begin(), nums.end());  
    int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];  // Три наибольших числа
    int product2 = nums[0] * nums[1] * nums[n - 1];          // Два наименьших и наибольшее положительное

    cout << max(product1, product2) << endl;

    return 0;
}
