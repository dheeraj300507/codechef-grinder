#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Approximate Answer
 * The problem asks to check if |X - Y| <= K.
 * Given constraints are small (1 <= X, Y, K <= 20), so standard integer types are sufficient.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single line of input per test case.
    // Although the prompt mentions "Handle multiple test cases", the problem 
    // description provided only specifies one line of input. 
    // We will read X, Y, and K and output the result.
    
    long long X, Y, K;
    if (cin >> X >> Y >> K) {
        // Calculate absolute difference
        long long diff = abs(X - Y);
        
        // Check condition |X - Y| <= K
        if (diff <= K) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}