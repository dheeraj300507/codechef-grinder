#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length n.
 * L(V) = S means V[1...n-1] + V[0] = S[0...n-1].
 * This implies V[i] = S[(i+1)%n].
 * R(V) = S means V[n-1] + V[0...n-2] = S[0...n-1].
 * This implies V[i] = S[(i-1+n)%n].
 * 
 * Combining these, we need a string V such that:
 * V is the left shift of S (let's call it L_S)
 * V is the right shift of S (let's call it R_S)
 * Therefore, we just need to check if L(S) == R(S).
 * 
 * L(S) = S[1...n-1] + S[0]
 * R(S) = S[n-1] + S[0...n-2]
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Construct L(S)
    string l_s = s.substr(1) + s[0];
    
    // Construct R(S)
    string r_s = s.back() + s.substr(0, n - 1);
    
    if (l_s == r_s) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}