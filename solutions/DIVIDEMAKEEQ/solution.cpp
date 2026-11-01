#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * 1. Calculate G = gcd(A_1, A_2, ..., A_N).
 * 2. Any common divisor V of the array must be a divisor of G.
 * 3. For a chosen common divisor V, the number of moves is (N - count of V in A).
 * 4. To minimize moves, we maximize the count of V in A.
 * 5. Find all divisors of G, and for each, count how many A_i are equal to it.
 *    Actually, since V must be a common divisor, if A_i is a multiple of V, 
 *    we can reduce it to V. The cost is 1 if A_i > V and 0 if A_i == V.
 *    So we want to maximize the number of elements equal to V.
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long g = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) g = a[i];
        else g = gcd(g, a[i]);
    }

    // Find all divisors of g
    vector<long long> divisors;
    for (long long i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i * i != g) divisors.push_back(g / i);
        }
    }

    int max_freq = 0;
    for (long long v : divisors) {
        int current_freq = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == v) current_freq++;
        }
        max_freq = max(max_freq, current_freq);
    }

    cout << n - max_freq << "\n";
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