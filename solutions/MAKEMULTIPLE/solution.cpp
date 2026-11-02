#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given A and B (A <= B). We need to find if there exists a non-negative integer X
 * such that (A + X) divides (B + X).
 * 
 * Let (A + X) = k, where k is a divisor of (B + X).
 * This means (B + X) = m * (A + X) for some integer m >= 1.
 * B + X = m*A + m*X
 * B - m*A = X(m - 1)
 * 
 * If m = 1:
 * B - A = X(0) => B - A = 0 => B = A.
 * If A = B, we can choose X = 0, so YES.
 * 
 * If m > 1:
 * X = (B - m*A) / (m - 1)
 * Since X must be a non-negative integer (X >= 0):
 * 1. (B - m*A) must be >= 0, so B >= m*A.
 * 2. (B - m*A) must be divisible by (m - 1).
 * 
 * Alternatively, consider the difference D = B - A.
 * If we add X to both, the new difference is (B + X) - (A + X) = B - A.
 * So the new divisor (A + X) must be a divisor of the new dividend (B + X).
 * Since (B + X) = (A + X) + (B - A), for (A + X) to divide (B + X),
 * (A + X) must divide (B - A).
 * 
 * Let D = B - A.
 * If D = 0, then A = B, which is always possible (X=0).
 * If D > 0, we need to find if there exists an X >= 0 such that (A + X) is a divisor of D.
 * This is equivalent to checking if there exists a divisor 'd' of D such that d >= A.
 * Because if such a 'd' exists, we can set A + X = d, which implies X = d - A.
 * Since d >= A, X >= 0.
 * 
 * So the condition is: Is there a divisor of (B - A) that is >= A?
 * This is true if and only if (B - A) == 0 OR (B - A) >= A.
 * Wait, let's re-check:
 * If B - A = 0, YES.
 * If B - A > 0, we need a divisor d of (B - A) such that d >= A.
 * The largest divisor of (B - A) is (B - A) itself.
 * If (B - A) >= A, then we can pick d = (B - A), which is a divisor of itself, and d >= A.
 * So the condition simplifies to: (B - A) == 0 OR (B - A) >= A.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    
    if (A == B) {
        cout << "YES" << "\n";
    } else {
        long long diff = B - A;
        if (diff >= A) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
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