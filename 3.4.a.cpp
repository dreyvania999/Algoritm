#include <iostream>
using namespace std;

void moveDisks(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << endl;
        return;
    }

       moveDisks(n - 1, from, aux, to);

        cout << from << " " << to << endl;

        moveDisks(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;

        int k = (1 << n) - 1;
    cout << k << endl;

        moveDisks(n, 1, 3, 2);  
    return 0;
}