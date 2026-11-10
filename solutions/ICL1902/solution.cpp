#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N circles. We need to form the largest possible square of side S (S^2 <= N).
 * After forming the square, we are left with N - S^2 circles.
 * We repeat this process until no circles are left.
 * Since N <= 1000, a simple greedy approach will work perfectly.
 * In each step, we find the largest integer S such that S*S <= N,
 * increment our count, and update N = N - S*S.
 */

void solve() {
    int N;
    cin >> N;
    
    int count = 0;
    while (N > 0) {
        // Find the largest integer S such that S*S <= N
        int s = sqrt(N);
        
        // Subtract the circles used for this square
        N -= (s * s);
        
        // Increment the number of squares formed
        count++;
    }
    
    cout << count << "\n";
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