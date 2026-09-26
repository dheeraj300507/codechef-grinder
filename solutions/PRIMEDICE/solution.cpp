#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob roll dice with values A and B (1 <= A, B <= 6).
 * The sum S = A + B ranges from 2 to 12.
 * Alice wins if S is prime.
 * Prime numbers in the range [2, 12] are: 2, 3, 5, 7, 11.
 * We can simply check if the sum is one of these values.
 */

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int sum = a + b;
        
        if (is_prime(sum)) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
    return 0;
}