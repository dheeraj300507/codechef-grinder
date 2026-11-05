#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a set of n integers (1 <= n <= 100) such that no three 
 * distinct elements a, b, c satisfy a + b = c. The elements must be in the range [1, 500].
 * 
 * A simple strategy is to pick large numbers. If we pick numbers from the upper end 
 * of the range [1, 500], say starting from 500 and going downwards, it becomes 
 * very difficult for the sum of two smaller numbers to equal a third number in the set.
 * 
 * Specifically, if we pick the set {500, 499, 498, ..., 500 - n + 1}, 
 * the smallest sum of two distinct elements is (500 - n + 1) + (500 - n + 2) = 1001 - 2n + 1.
 * Since n <= 100, the smallest sum is at least 1001 - 200 + 1 = 802.
 * Since all our elements are <= 500, no two elements can sum to a third element 
 * present in the set.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // We output n integers starting from 500 downwards.
        // For n=100, the smallest number is 500 - 100 + 1 = 401.
        // The smallest sum of two distinct elements is 401 + 402 = 803.
        // Since 803 > 500, no sum can be in the set.
        for (int i = 0; i < n; ++i) {
            cout << (500 - i) << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}