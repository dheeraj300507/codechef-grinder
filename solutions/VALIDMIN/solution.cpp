#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x = min(A, B), y = min(B, C), z = min(C, A).
 * Without loss of generality, assume A <= B <= C.
 * Then:
 * min(A, B) = A
 * min(B, C) = B
 * min(C, A) = A
 * So, A = x, B = y, A = z.
 * This implies x = z.
 * 
 * More generally, if we sort the three given values as m1 <= m2 <= m3:
 * The two smallest values must be equal.
 * If the two smallest values are equal, say m1 == m2, then we can set:
 * A = m1, B = m1, C = m3.
 * Then:
 * min(A, B) = min(m1, m1) = m1
 * min(B, C) = min(m1, m3) = m1
 * min(C, A) = min(m3, m1) = m1
 * Wait, this only works if m1 == m2.
 * Let's re-evaluate:
 * If we have values x, y, z.
 * If two are equal and the third is greater than or equal to them, it is possible.
 * Example: 2, 2, 4. Sorted: 2, 2, 4.
 * Let A=2, B=2, C=4.
 * min(A, B) = 2
 * min(B, C) = 2
 * min(C, A) = 2
 * Wait, the sample says 2, 2, 4 is YES.
 * Let's check: A=2, B=2, C=4.
 * min(A, B) = 2
 * min(B, C) = 2
 * min(C, A) = 2
 * The input is 2, 2, 4. My manual check:
 * If A=2, B=2, C=4:
 * min(A, B) = 2
 * min(B, C) = 2
 * min(C, A) = 2
 * This doesn't match 2, 2, 4.
 * Let's try A=4, B=2, C=5.
 * min(A, B) = 2
 * min(B, C) = 2
 * min(C, A) = 4
 * This matches 2, 2, 4.
 * 
 * Conclusion:
 * Sort the three inputs: m1 <= m2 <= m3.
 * The condition for a valid tuple is m1 == m2.
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}