#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length N.
 * L(V) = S implies V[1...N-1] + V[0] = S[0...N-1]
 * This means V[i] = S[(i+1) % N]
 * 
 * R(V) = S implies V[N-1] + V[0...N-2] = S[0...N-1]
 * This means V[i] = S[(i-1+N) % N]
 * 
 * For a string V to exist such that L(V) = S and R(V) = S,
 * we must have S[(i+1) % N] = S[(i-1+N) % N] for all i.
 * 
 * Let's test the shifts:
 * If we shift S left by 1, we get L(S).
 * If we shift S right by 1, we get R(S).
 * The condition L(V) = S and R(V) = S is equivalent to checking if 
 * the left shift of S is equal to the right shift of S.
 * 
 * Example: S = "abcd"
 * L(S) = "bcda"
 * R(S) = "dabc"
 * L(S) != R(S), so NO.
 * 
 * Example: S = "ab"
 * L(S) = "ba"
 * R(S) = "ba"
 * L(S) == R(S), so YES.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Left shift of S: s[1...n-1] + s[0]
    string left_shifted = s.substr(1) + s[0];
    
    // Right shift of S: s[n-1] + s[0...n-2]
    string right_shifted = s.back() + s.substr(0, n - 1);
    
    if (left_shifted == right_shifted) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
    }
    return 0;
}