#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want all elements in the array to have the same parity (all even or all odd).
 * 
 * Parity rules:
 * - Odd + Odd = Even
 * - Even + Even = Even
 * - Odd + Even = Odd
 * 
 * If we want all elements to be ODD:
 * - Any odd number is already fine.
 * - Any even number can be split into (Odd + Odd). This takes 1 operation.
 * - So, to make all elements odd, we need to change every even number into two odds.
 *   Number of operations = count of even numbers.
 * 
 * If we want all elements to be EVEN:
 * - Any even number is already fine.
 * - Any odd number can be split into (Odd + Even). This doesn't help make it even.
 *   To make an odd number even, we would need to split it into (Odd + Odd) which is even,
 *   but that requires at least two operations or specific conditions. Actually, 
 *   an odd number cannot be split into two even numbers because Even + Even = Even (not Odd).
 *   Therefore, we can never make an odd number even by splitting it.
 * 
 * Conclusion:
 * - If there are no odd numbers, the array is already all even (0 operations).
 * - If there are odd numbers, we can only make the whole array odd.
 * - To make the whole array odd, every even number must be split into two odd numbers.
 * - If there are no even numbers, we need 0 operations.
 * - If there are even numbers, we need exactly the count of even numbers to make them all odd.
 * 
 * Wait, what if the array has both?
 * If we have at least one odd number, we can make all even numbers odd by splitting them.
 * If we have no odd numbers, the array is already all even.
 * Thus, the answer is simply the count of even numbers if there is at least one odd number.
 * If there are no odd numbers, the answer is 0.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == 0) {
        // All are even, already same parity
        cout << 0 << "\n";
    } else {
        // We can make all even numbers odd by splitting them.
        // Each even number takes 1 operation to become two odd numbers.
        cout << even_count << "\n";
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