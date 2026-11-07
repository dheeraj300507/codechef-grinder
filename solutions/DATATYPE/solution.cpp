#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The data type stores values in the range [0, N].
 * This means there are N + 1 possible values (0, 1, 2, ..., N).
 * When a value X is provided, if X > N, it wraps around.
 * The wrap-around behavior is equivalent to the modulo operation.
 * Specifically, the value stored is X % (N + 1).
 * 
 * Example 1: N=15, X=0. 0 % 16 = 0. Correct.
 * Example 3: N=11, X=12. 12 % 12 = 0. Correct.
 * Example 4: N=27, X=37. 37 % 28 = 9. Correct.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // The range is 0 to N, so there are N + 1 distinct values.
        // The cyclic behavior is defined by modulo (N + 1).
        long long result = x % (n + 1);
        
        cout << result << "\n";
    }
    
    return 0;
}