#include <iostream>
#include <utility>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	if (n > m) swap(n, m);

	if (n == m || ((n - m) % 3 == 0)) {
		cout << "Lose";
	}
	else {
		cout << "Win";
	}

	return 0;
}