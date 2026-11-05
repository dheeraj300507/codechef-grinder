#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the total number of candies: S = sum(A_i).
 * Let X be the number of candies Sammy gets and Y be the number of candies Simmy gets.
 * We are given:
 * 1) X + Y = S
 * 2) X > Y (Sammy is happy)
 * 3) |X - Y| <= 1 (Simmy is happy)
 * 
 * From (3), X - Y can be -1, 0, or 1.
 * Since X > Y, X - Y must be 1.
 * So, X = Y + 1.
 * Substituting into (1): (Y + 1) + Y = S => 2Y + 1 = S => 2Y = S - 1.
 * For Y to be an integer, S - 1 must be even, which means S must be odd.
 * If S is odd, we can always set Y = (S - 1) / 2 and X = (S + 1) / 2.
 * Then X > Y (since (S+1)/2 > (S-1)/2) and X - Y = 1 (which satisfies |X-Y| <= 1).
 * If S is even, 2Y = S - 1 would result in Y being a non-integer, which is impossible 
 * since we need to distribute the total sum.
 * 
 * Therefore, the condition is simply: Is the total sum of candies odd?
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            total_sum += a;
        }

        // If total sum is odd, it's possible to satisfy both conditions.
        if (total_sum % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}