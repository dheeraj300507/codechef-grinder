#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to count its odd divisors and even divisors.
 * A divisor 'd' of N is odd if 'd' is not divisible by 2.
 * A divisor 'd' of N is even if 'd' is divisible by 2.
 * 
 * Since N is small (1 <= N <= 100), we can iterate from 1 to N to find all divisors.
 * For each divisor 'i', we check if it divides N (N % i == 0).
 * If it does, we check if it is odd or even and increment the respective counter.
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_count = 0;
    int even_count = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            if (i % 2 != 0) {
                odd_count++;
            } else {
                even_count++;
            }
        }
    }
    
    cout << odd_count << " " << even_count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}