#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: PRIME1 - Prime Generator
 * Approach: Segmented Sieve
 * Since n can be up to 10^9 but n-m is small (10^5), we can use a segmented sieve.
 * 1. Precompute primes up to sqrt(10^9) ≈ 31622 using a simple sieve.
 * 2. For each test case [m, n], create a boolean array of size (n-m+1).
 * 3. Mark non-primes in the range [m, n] using the precomputed primes.
 */

void solve() {
    long long m, n;
    cin >> m >> n;

    if (m < 2) m = 2;
    if (m > n) return;

    int limit = sqrt(n) + 1;
    vector<int> primes;
    vector<bool> is_prime_small(limit + 1, true);
    is_prime_small[0] = is_prime_small[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime_small[p]) {
            for (int i = p * p; i <= limit; i += p)
                is_prime_small[i] = false;
        }
    }
    for (int p = 2; p <= limit; p++) {
        if (is_prime_small[p]) primes.push_back(p);
    }

    vector<bool> is_prime_range(n - m + 1, true);

    for (int p : primes) {
        // Find the first multiple of p in [m, n]
        long long start = (m + p - 1) / p * p;
        if (start < (long long)p * p) start = (long long)p * p;
        
        for (long long j = start; j <= n; j += p) {
            is_prime_range[j - m] = false;
        }
    }

    for (long long i = m; i <= n; i++) {
        if (is_prime_range[i - m]) {
            cout << i << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t > 0) cout << "\n";
    }
    return 0;
}