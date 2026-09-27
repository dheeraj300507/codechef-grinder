#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The binary parity of N is defined by the parity of the sum of its binary digits.
 * This is equivalent to the population count (number of set bits) of N.
 * If the number of set bits is even, the parity is EVEN.
 * If the number of set bits is odd, the parity is ODD.
 * 
 * In C++, __builtin_popcount(N) returns the number of set bits in an integer.
 * Since N <= 10^9, it fits within a standard 32-bit signed integer.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        // __builtin_popcount returns the number of 1s in the binary representation
        int set_bits = __builtin_popcount(n);
        
        // Check if the count is even or odd
        if (set_bits % 2 == 0) {
            cout << "EVEN" << "\n";
        } else {
            cout << "ODD" << "\n";
        }
    }
    
    return 0;
}