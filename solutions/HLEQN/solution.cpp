#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The equation is 2a + 2b + ab = X.
 * We can use Simon's Favorite Factoring Trick:
 * Add 4 to both sides:
 * ab + 2a + 2b + 4 = X + 4
 * (a + 2)(b + 2) = X + 4
 * 
 * Let A = a + 2 and B = b + 2.
 * Since a > 0 and b > 0, we must have A > 2 and B > 2.
 * The equation becomes A * B = X + 4.
 * 
 * We need to check if there exist factors A and B of (X + 4) such that
 * A > 2 and B > 2.
 * Since A * B = X + 4, if we find a divisor A of (X + 4), then B = (X + 4) / A.
 * We just need to check if there exists a divisor A such that 2 < A < (X + 4) / 2.
 * Actually, checking 3 <= A <= sqrt(X + 4) is sufficient.
 */

void solve() {
    long long X;
    cin >> X;
    long long target = X + 4;
    bool found = false;
    
    // We look for a divisor 'a_plus_2' of 'target'
    // such that a_plus_2 > 2 and (target / a_plus_2) > 2.
    // The smallest possible value for a_plus_2 is 3.
    // The largest possible value for a_plus_2 is (target / 3).
    for (long long i = 3; i * i <= target; ++i) {
        if (target % i == 0) {
            long long j = target / i;
            if (i > 2 && j > 2) {
                found = true;
                break;
            }
        }
    }
    
    if (found) {
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