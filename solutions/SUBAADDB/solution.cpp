#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with a string of length N.
 * In each step, we replace a substring of length A with a substring of length B.
 * This reduces the total length of the string by (A - B).
 * We repeat this as long as the current length L >= A.
 * 
 * Let L be the current length.
 * While L >= A:
 *    L = L - A + B
 * 
 * Since N is small (up to 100), we can simulate this process directly.
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;

    int current_length = N;
    
    // While the string length is at least A, we can perform the operation.
    // Each operation reduces the length by (A - B).
    while (current_length >= A) {
        current_length = current_length - A + B;
    }
    
    cout << current_length << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}