#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different palindromic binary strings with A zeros and B ones.
 * 
 * Case 1: If both A and B are odd, it is impossible to form even one palindrome.
 * Why? A palindrome with A zeros and B ones where both are odd must have the middle 
 * element as the character that appears an odd number of times. If both are odd, 
 * we would need two middle elements, which is impossible.
 * 
 * Case 2: If either A or B is 1:
 * If A=1 and B is even, we can only form one palindrome (e.g., 11011).
 * If A=1 and B is odd, we can only form one palindrome (e.g., 111).
 * Generally, if A=1 or B=1, we can only form one unique palindrome structure.
 * 
 * Case 3: If both A and B are even:
 * We can always form at least two distinct palindromes.
 * Example: A=2, B=2 -> "0110" and "1001".
 * 
 * Case 4: If one is even and one is odd:
 * We can always form at least two distinct palindromes.
 * Example: A=2, B=3 -> "01110" and "10101".
 * 
 * Summary:
 * - If (A % 2 != 0 && B % 2 != 0): No
 * - If (A == 1 || B == 1): No
 * - Otherwise: Yes
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
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