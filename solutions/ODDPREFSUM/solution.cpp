#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the array be B = [B_1, B_2, ..., B_N].
 * We want prefix sums S_i = B_1 + ... + B_i to be odd for all i.
 * 
 * S_1 = B_1 must be odd.
 * S_2 = S_1 + B_2 must be odd. Since S_1 is odd, B_2 must be even.
 * S_3 = S_2 + B_3 must be odd. Since S_2 is odd, B_3 must be even.
 * ...
 * S_i = S_{i-1} + B_i must be odd. Since S_{i-1} is odd, B_i must be even.
 * 
 * Therefore, for all i > 1, B_i must be even.
 * This means we need exactly one odd number to start the array, and all remaining 
 * numbers in the array must be even.
 * 
 * Let 'odd_count' be the number of odd integers in the input array A.
 * Let 'even_count' be the number of even integers in the input array A.
 * 
 * The condition is satisfied if and only if:
 * 1. odd_count == 1 (We need exactly one odd number to start the sequence).
 * 2. The remaining N-1 numbers must be even.
 * 
 * Wait, let's re-check:
 * If we have one odd number and some even numbers, we place the odd number first.
 * The prefix sum S_1 is odd.
 * Every subsequent element is even, so S_i = S_{i-1} + even = odd + even = odd.
 * This works.
 * 
 * What if we have more than one odd number?
 * If we have two odd numbers, say O1 and O2, and some even numbers.
 * If we place O1 first, S_1 is odd. If we place O2 later, the prefix sum at that 
 * position will become (odd + ... + O2) = (odd + odd) = even.
 * So we cannot have more than one odd number.
 * 
 * What if we have zero odd numbers?
 * S_1 would be even, which is not allowed.
 * 
 * Conclusion: The condition is satisfied if and only if there is exactly one odd number.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count == 1) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}