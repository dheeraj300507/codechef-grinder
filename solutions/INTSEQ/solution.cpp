#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given A_i + S_i = K, where S_i = A_1 + ... + A_i.
 * For i = 1: A_1 + S_1 = A_1 + A_1 = 2*A_1 = K.
 * For i > 1: A_i + S_i = K and A_{i-1} + S_{i-1} = K.
 * Since S_i = S_{i-1} + A_i, we have:
 * A_i + S_{i-1} + A_i = K
 * 2*A_i = K - S_{i-1}
 * From the previous step, S_{i-1} = K - A_{i-1}.
 * So, 2*A_i = K - (K - A_{i-1}) = A_{i-1}.
 * This implies A_i = A_{i-1} / 2.
 * 
 * For the sequence to be integers, each A_i must be an integer.
 * This means A_1 must be divisible by 2^(N-1).
 * We know 2*A_1 = K, so A_1 = K / 2.
 * Thus, K / 2 must be divisible by 2^(N-1).
 * Let K = 2^p * m, where m is odd.
 * Then A_1 = 2^(p-1) * m.
 * For A_N to be an integer, 2^(p-1) must be divisible by 2^(N-1).
 * This means p-1 >= N-1, or N <= p.
 * To maximize N, we take N = p, where p is the exponent of the highest power of 2 
 * that divides K.
 */

void solve() {
    long long K;
    cin >> K;
    
    // We need to find the exponent of the highest power of 2 that divides K.
    // This is equivalent to counting how many times we can divide K by 2.
    int count = 0;
    while (K > 0 && K % 2 == 0) {
        count++;
        K /= 2;
    }
    cout << count << "\n";
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