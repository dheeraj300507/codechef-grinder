#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are allowed to reverse any substring of length X, where X is a prime number.
 * 
 * Key Insight:
 * 1. If we can reverse a substring of length 2, we can swap any two adjacent elements.
 *    (Since 2 is prime).
 * 2. If we can swap any two adjacent elements, we can perform any permutation of the string.
 * 3. However, we only have prime lengths. Can we swap any two adjacent elements?
 *    - If we have a substring of length 2, we can swap A[i] and A[i+1].
 *    - If we have a substring of length 3, we can reverse A[i...i+2].
 *      Reversing A[i...i+2] is equivalent to swapping A[i] and A[i+2].
 * 
 * Since we can swap adjacent elements (using length 2) and swap elements at distance 2 (using length 3),
 * we can effectively move any '1' to any position and any '0' to any position.
 * 
 * Wait, is length 2 always available? 
 * If N >= 2, we can use 2. If N=1, we can't do anything.
 * Actually, the problem implies we can perform these operations any number of times.
 * With prime lengths 2 and 3, we can generate any permutation of the string because 
 * the greatest common divisor of (2, 3) is 1.
 * 
 * Therefore, the condition for A to be transformable into B is simply that 
 * both strings must have the same number of '1's and the same number of '0's.
 */

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int countA1 = 0, countA0 = 0;
    int countB1 = 0, countB0 = 0;

    for (char c : a) {
        if (c == '1') countA1++;
        else countA0++;
    }

    for (char c : b) {
        if (c == '1') countB1++;
        else countB0++;
    }

    if (countA1 == countB1 && countA0 == countB0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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