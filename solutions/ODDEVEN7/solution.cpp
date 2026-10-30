#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A "good" array has alternating parity (Odd, Even, Odd, Even... or Even, Odd, Even, Odd...).
 * Let 'odd_count' be the number of odd integers in the input array.
 * Let 'even_count' be the number of even integers in the input array.
 * 
 * To form an alternating sequence:
 * 1. If odd_count == even_count, we can use all elements (e.g., O, E, O, E...). Total = 2 * odd_count.
 * 2. If odd_count != even_count, we can take the smaller count and match it with the larger count.
 *    We can pick 'min(odd_count, even_count)' elements of one parity and 'min(odd_count, even_count) + 1' 
 *    elements of the other parity.
 *    Total = 2 * min(odd_count, even_count) + 1.
 * 
 * Combining these:
 * If odd_count == even_count, result is odd_count + even_count.
 * If odd_count != even_count, result is 2 * min(odd_count, even_count) + 1.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == even_count) {
        cout << odd_count + even_count << "\n";
    } else {
        cout << 2 * min(odd_count, even_count) + 1 << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}