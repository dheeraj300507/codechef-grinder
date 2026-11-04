#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * For even N: f(N) = N^2/4 + N/2
 * For odd N: f(N) = ((N+1)/2)^2
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n % 2 == 0) {
            cout << (n * n) / 4 + n / 2 << "\n";
        } else {
            long long k = (n + 1) / 2;
            cout << k * k << "\n";
        }
    }
    return 0;
}