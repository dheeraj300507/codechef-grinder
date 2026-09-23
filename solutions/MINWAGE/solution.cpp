#include <iostream>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // The problem states the minimum wage is 11.
    // We need to check if X is strictly greater than 11.
    if (X > 11) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}