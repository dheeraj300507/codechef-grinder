#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with an integer N. We want to break it into powers of 2.
 * An operation consists of taking an integer X and splitting it into Y + Z = X.
 * If we start with N, and we want to reach a state where all numbers are powers of 2,
 * this is equivalent to finding the binary representation of N.
 * 
 * If N = 2^a1 + 2^a2 + ... + 2^ak, then N has k set bits in its binary representation.
 * To reach this state from N, we need to perform (k - 1) operations.
 * 
 * Example: N = 3 (binary 11). k = 2. Operations = 2 - 1 = 1.
 * Example: N = 4 (binary 100). k = 1. Operations = 1 - 1 = 0.
 * Example: N = 7 (binary 111). k = 3. Operations = 3 - 1 = 2.
 * 
 * The number of set bits can be calculated using __builtin_popcount(N).
 * Since N <= 10^9, it fits in a standard 32-bit integer, but using long long is safe.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // __builtin_popcount returns the number of set bits (1s) in the binary representation.
        // The minimum number of operations to split N into powers of 2 is (popcount(N) - 1).
        int set_bits = 0;
        long long temp = n;
        while (temp > 0) {
            if (temp & 1) set_bits++;
            temp >>= 1;
        }
        
        cout << set_bits - 1 << "\n";
    }
    
    return 0;
}