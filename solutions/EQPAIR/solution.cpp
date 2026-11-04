#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are looking for pairs (i, j) such that gcd(A_i, A_j) = lcm(A_i, A_j).
 * We know that for any two positive integers a and b:
 * gcd(a, b) * lcm(a, b) = a * b
 * 
 * Substituting the condition gcd(a, b) = lcm(a, b) = k:
 * k * k = a * b
 * Since k = gcd(a, b), k must divide both a and b.
 * Let a = k * x and b = k * y, where gcd(x, y) = 1.
 * Then lcm(a, b) = k * x * y.
 * The condition gcd(a, b) = lcm(a, b) implies:
 * k = k * x * y
 * Since k > 0, we have 1 = x * y.
 * Since x and y are positive integers, this implies x = 1 and y = 1.
 * Therefore, a = k and b = k, which means a = b.
 * 
 * Conclusion:
 * A pair (i, j) is "good" if and only if A_i = A_j.
 * If a number x appears 'f' times in the array, the number of good pairs 
 * that can be formed using this number is the number of ways to choose 2 
 * indices out of 'f', which is f * (f - 1) / 2.
 */

void solve() {
    int n;
    cin >> n;
    
    // Using a map to count frequencies of each number.
    // Since N <= 10^5 and A_i <= 10^9, a map is efficient (O(N log N)).
    map<int, long long> counts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }
    
    long long total_good_pairs = 0;
    for (auto const& [val, freq] : counts) {
        if (freq > 1) {
            total_good_pairs += (freq * (freq - 1)) / 2;
        }
    }
    
    cout << total_good_pairs << "\n";
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