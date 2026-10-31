#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X rupees initially and Y years.
 * Each year, he can either:
 * 1. Add 1000: X = X + 1000
 * 2. Double: X = X * 2
 * 
 * Since Y is very small (up to 10), we want to maximize X.
 * Comparing the two operations:
 * If we have amount A, adding 1000 results in A + 1000.
 * Doubling results in 2 * A.
 * 2 * A > A + 1000 if A > 1000.
 * If A < 1000, adding 1000 is better.
 * If A == 1000, both are equal.
 * 
 * Given Y is at most 10, we can greedily decide at each step.
 * At any year, if we have amount A, we compare (A + 1000) * 2^(remaining_years - 1) 
 * vs (A * 2) * 2^(remaining_years - 1).
 * Actually, it is simpler: at each step, we choose the operation that results in a larger value.
 * Since the doubling operation is multiplicative and adding 1000 is additive, 
 * it is always optimal to perform the addition first if the current amount is small, 
 * and then perform the doubling for the remaining years.
 * 
 * Specifically, for each year, we check if (X + 1000) * 2 > (X * 2) + 1000.
 * (X + 1000) * 2 = 2X + 2000
 * (X * 2) + 1000 = 2X + 1000
 * Since 2X + 2000 > 2X + 1000, it is always better to add 1000 before doubling.
 * Thus, the strategy is: for each year, compare (X + 1000) and (X * 2) and pick the max.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        for (int i = 0; i < y; ++i) {
            long long add_option = x + 1000;
            long long double_option = x * 2;
            
            if (add_option > double_option) {
                x = add_option;
            } else {
                x = double_option;
            }
        }
        cout << x << "\n";
    }

    return 0;
}