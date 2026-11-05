#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a candy of length N and we eat K units per bite.
 * We can eat the entire candy if and only if N is perfectly divisible by K.
 * If N % K == 0, the number of bites is N / K.
 * If N % K != 0, we will eventually be left with a remainder (N % K) which is 
 * greater than 0 but less than K, meaning we cannot finish the candy.
 * 
 * Special case: If N = 0, we have already eaten the candy, so 0 bites.
 * Constraints: N, K up to 10^6, T up to 10^5. O(1) per test case is required.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // If candy length is 0, we need 0 bites.
        if (n == 0) {
            cout << 0 << "\n";
        } 
        // If N is divisible by K, we can finish it in N/K bites.
        else if (n % k == 0) {
            cout << (n / k) << "\n";
        } 
        // Otherwise, we are left with a remainder < K, so it's impossible.
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}