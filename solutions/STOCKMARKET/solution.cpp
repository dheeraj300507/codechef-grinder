#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - (A_i that is skipped).
 * To maximize the total profit, we need to minimize the value of the skipped day (A_i).
 * Therefore, the strategy is:
 * 1. Calculate the sum of all elements in the array.
 * 2. Find the minimum element in the array.
 * 3. The result is (Sum - Minimum Element).
 * 
 * Constraints:
 * N <= 10^5, Sum of N <= 10^6.
 * A_i between -100 and 100.
 * The sum can be at most 10^5 * 100 = 10^7, which fits in a standard 32-bit integer,
 * but using long long is safer and good practice.
 */

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    long long total_sum = 0;
    long long min_val = 200; // Since max A_i is 100, 200 is a safe initial value
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }
    
    // We skip the day with the minimum profit to maximize the remaining sum.
    cout << (total_sum - min_val) << "\n";
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