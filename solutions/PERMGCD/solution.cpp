#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation P of {1, 2, ..., N} such that sum of prefix GCDs equals X.
 * The minimum possible sum of prefix GCDs for any permutation is N (when the GCD 
 * becomes 1 immediately at the first element or stays 1).
 * The maximum possible sum is when the first element is a multiple of g, 
 * and we can maintain a GCD of g for some steps.
 * 
 * Strategy:
 * If X < N, it's impossible, return -1.
 * If we pick a number 'g' such that 1 <= g <= N, we can start our permutation 
 * with 'g', then follow with multiples of 'g' (2g, 3g, ...), then the rest of 
 * the numbers.
 * 
 * Specifically, if we start with [g, 2g, 3g, ..., kg], the prefix GCDs will be:
 * g, g, g, ..., g (k times). Sum = k * g.
 * After this, we need the remaining (N-k) elements to contribute (X - k*g) to the sum.
 * Since the GCD will become 1 after adding any number not divisible by g, 
 * the remaining (N-k) elements will contribute exactly (N-k) to the sum.
 * 
 * So, X = k*g + (N-k).
 * X - N = k*g - k = k(g - 1).
 * We need to find g such that (X - N) is divisible by (g - 1).
 * Since 1 <= g <= N, we can iterate through all possible g.
 */

void solve() {
    int N, X;
    cin >> N >> X;

    if (X < N) {
        cout << -1 << "\n";
        return;
    }

    // Try all possible starting GCDs 'g'
    for (int g = 1; g <= N; ++g) {
        // We want to see if we can achieve X using g as the prefix GCD for some k elements.
        // The sum is k*g + (N-k) = X
        // k(g-1) = X - N
        // If g=1, then X-N must be 0, so k can be anything (let's pick k=1).
        if (g == 1) {
            if (X == N) {
                for (int i = 1; i <= N; ++i) cout << i << (i == N ? "" : " ");
                cout << "\n";
                return;
            }
            continue;
        }

        if ((X - N) % (g - 1) == 0) {
            int k = (X - N) / (g - 1);
            if (k >= 1 && k <= N / g) {
                vector<bool> used(N + 1, false);
                vector<int> res;
                
                // Add multiples of g
                for (int i = 1; i <= k; ++i) {
                    res.push_back(i * g);
                    used[i * g] = true;
                }
                
                // Add remaining numbers
                for (int i = 1; i <= N; ++i) {
                    if (!used[i]) {
                        res.push_back(i);
                    }
                }
                
                for (int i = 0; i < N; ++i) cout << res[i] << (i == N - 1 ? "" : " ");
                cout << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
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