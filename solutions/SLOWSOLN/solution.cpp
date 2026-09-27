#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of squares of N_i, given:
 * 1. 1 <= T <= maxT
 * 2. 1 <= N_i <= maxN
 * 3. Sum(N_i) <= sumN
 * 
 * To maximize the sum of squares, we want the values of N_i to be as large as possible.
 * Since the function f(x) = x^2 is convex, we should make as many N_i as possible 
 * equal to maxN.
 * 
 * Strategy:
 * 1. We can have at most maxT test cases.
 * 2. We want to fill as many test cases as possible with the value maxN.
 * 3. Let k = sumN / maxN.
 * 4. If k < maxT, we can have k test cases with value maxN, and one remaining 
 *    test case with value (sumN % maxN). This uses k+1 test cases, which is <= maxT.
 * 5. If k >= maxT, we are limited by the number of test cases (maxT). 
 *    We should set maxT - 1 test cases to maxN, and the last test case to 
 *    (sumN - (maxT - 1) * maxN).
 */

void solve() {
    long long maxT, maxN, sumN;
    cin >> maxT >> maxN >> sumN;

    long long num_full = sumN / maxN;
    long long remainder = sumN % maxN;

    long long total_iterations = 0;

    if (num_full >= maxT) {
        // We are limited by the number of test cases.
        // We use maxT test cases of size maxN.
        total_iterations = maxT * (maxN * maxN);
    } else {
        // We can use num_full test cases of size maxN, 
        // and one test case of size remainder.
        total_iterations = num_full * (maxN * maxN) + (remainder * remainder);
    }

    cout << total_iterations << "\n";
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