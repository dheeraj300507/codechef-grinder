#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N chocolates into three jars (a, b, c) such that:
 * 1. a + b + c = N
 * 2. At least one jar has an odd number of chocolates.
 * 3. Exactly two jars have the same number of chocolates.
 * 4. a, b, c >= 1
 * 
 * Strategy:
 * Let the two equal jars have x chocolates each.
 * Then the third jar has (N - 2x) chocolates.
 * We need N - 2x >= 1, so 2x <= N - 1, or x <= (N - 1) / 2.
 * 
 * Case 1: N is even.
 * Let x = 1. Then the jars are (1, 1, N - 2).
 * - Two jars are equal (1, 1).
 * - If N - 2 is odd, we have at least one odd (all three are odd).
 * - If N - 2 is even, we have at least one odd (the two 1s).
 * - Since N >= 4, N - 2 >= 2.
 * - This works for all even N.
 * 
 * Case 2: N is odd.
 * Let x = (N - 1) / 2. Then the jars are (x, x, 1).
 * - Two jars are equal (x, x).
 * - If x is odd, we have three odd numbers.
 * - If x is even, we have one odd number (the 1).
 * - Since N >= 5 (as N is odd and N >= 4), x >= 2.
 * - This works for all odd N.
 */

void solve() {
    long long N;
    cin >> N;

    if (N % 2 == 0) {
        // Even N: (1, 1, N-2)
        // Two jars are 1, 1 (equal).
        // N-2 is even, but 1 is odd. Condition "at least one odd" satisfied.
        cout << 1 << " " << 1 << " " << (N - 2) << "\n";
    } else {
        // Odd N: ((N-1)/2, (N-1)/2, 1)
        // Two jars are (N-1)/2, (N-1)/2 (equal).
        // 1 is odd. Condition "at least one odd" satisfied.
        long long x = (N - 1) / 2;
        cout << x << " " << x << " " << 1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}