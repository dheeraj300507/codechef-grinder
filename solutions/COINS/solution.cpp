#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a coin of value n, we have two choices:
 * 1. Keep the coin and exchange it for n dollars.
 * 2. Exchange the coin for three coins of values floor(n/2), floor(n/3), and floor(n/4).
 * 
 * Let f(n) be the maximum dollars we can get from a coin of value n.
 * f(n) = max(n, f(floor(n/2)) + f(floor(n/3)) + f(floor(n/4)))
 * 
 * Since n can be up to 10^9, we cannot use a simple array for memoization.
 * However, notice that for small n, f(n) = n. Specifically, for n < 12, 
 * the sum of floor(n/2) + floor(n/3) + floor(n/4) is always <= n.
 * We can use a map or a small array for memoization of larger values.
 */

map<long long, long long> memo;

long long solve(long long n) {
    if (n == 0) return 0;
    if (n < 12) return n;
    
    // Check if already computed
    if (memo.count(n)) return memo[n];
    
    // Recursive step: max of current value or sum of sub-coins
    long long res = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
    
    return memo[n] = res;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    // The problem states "several test cases", usually read until EOF
    while (cin >> n) {
        cout << solve(n) << "\n";
    }
    
    return 0;
}