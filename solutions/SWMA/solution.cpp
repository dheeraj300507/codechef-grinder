#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has score A (two digits, no zero).
 * Bob has score B (two digits, no zero).
 * Alice can reverse her score (A_rev) and/or Bob's score (B_rev).
 * There are 4 possible scenarios for the final scores (A', B'):
 * 1. (A, B)
 * 2. (A_rev, B)
 * 3. (A, B_rev)
 * 4. (A_rev, B_rev)
 * 
 * We need to check if in any of these scenarios, A' > B'.
 * Since A and B are two-digit numbers, reversing a number 'xy' results in 'yx'.
 * Given A = 10*a1 + a0, A_rev = 10*a0 + a1.
 */

int reverse_num(int n) {
    int tens = n / 10;
    int ones = n % 10;
    return ones * 10 + tens;
}

void solve() {
    int A, B;
    cin >> A >> B;
    
    int A_rev = reverse_num(A);
    int B_rev = reverse_num(B);
    
    // Check all 4 combinations
    if (A > B || A_rev > B || A > B_rev || A_rev > B_rev) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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