#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Initial money: X
 * - Cost of one laddu: 10
 * - Number of laddus bought: N
 * - Cost of one jalebi: 20
 * 
 * Calculation:
 * 1. Total cost of laddus = 10 * N
 * 2. Remaining money = X - (10 * N)
 * 3. Number of jalebis = Remaining money / 20 (integer division)
 * 
 * Constraints:
 * 1 <= X <= 100
 * 1 <= N <= 10
 * 10 * N <= X
 * 
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case structure based on the 
    // sample input format, but standard competitive programming practice 
    // often involves reading until EOF or a specified number of test cases.
    // Given the prompt asks to "Handle multiple test cases", we implement the loop.
    
    int X, N;
    // Reading input until EOF to handle multiple test cases if provided
    while (cin >> X >> N) {
        long long remaining_money = (long long)X - (10LL * N);
        long long jalebis = remaining_money / 20LL;
        
        cout << jalebis << "\n";
    }

    return 0;
}