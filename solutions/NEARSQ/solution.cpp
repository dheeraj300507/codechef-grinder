#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an integer N (1 <= N <= 100).
 * We need to find the largest square number A such that 1 <= A <= N.
 * Since N is small (up to 100), we can find the integer square root of N,
 * let's call it B = floor(sqrt(N)).
 * The largest square number A <= N will be B * B.
 * 
 * Example:
 * N = 10: sqrt(10) = 3.16..., floor is 3. 3 * 3 = 9.
 * N = 48: sqrt(48) = 6.92..., floor is 6. 6 * 6 = 36.
 * N = 1: sqrt(1) = 1.0, floor is 1. 1 * 1 = 1.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate the integer square root
        long long b = (long long)sqrt(n);
        
        // The largest square <= N is b * b
        long long result = b * b;
        
        cout << result << "\n";
    }
    
    return 0;
}