#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The number of trailing zeros in N! is determined by the number of times 
 * the factor 10 appears in the prime factorization of N!.
 * Since 10 = 2 * 5, and there are always more factors of 2 than 5 in any 
 * factorial, the number of trailing zeros is equal to the number of times 
 * the factor 5 appears in the prime factorization of N!.
 * 
 * According to Legendre's Formula, the exponent of a prime p in the 
 * prime factorization of N! is given by:
 * E_p(N!) = floor(N/p) + floor(N/p^2) + floor(N/p^3) + ...
 * 
 * Here, p = 5. We calculate floor(N/5) + floor(N/25) + floor(N/125) + ...
 * until the power of 5 exceeds N.
 * 
 * Complexity:
 * For each test case, the loop runs O(log_5(N)) times.
 * With T = 100,000 and N = 10^9, log_5(10^9) is approximately 13.
 * Total complexity: O(T * log_5(N)), which is well within the 8s time limit.
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;
    
    long long count = 0;
    // Divide n by powers of 5 and add to count
    while (n >= 5) {
        n /= 5;
        count += n;
    }
    cout << count << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}