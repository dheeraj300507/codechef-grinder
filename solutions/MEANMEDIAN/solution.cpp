#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find A, B, C such that:
 * 1. (A + B + C) / 3 = X  => A + B + C = 3 * X
 * 2. Median(A, B, C) = Y
 * 
 * Let's fix the median B = Y.
 * Then A + C = 3 * X - Y.
 * To satisfy the median condition, we need one of the remaining two numbers 
 * to be <= Y and the other to be >= Y.
 * 
 * Let A = Y - k and C = Y + (3 * X - Y - (Y - k)) = Y + 3 * X - 2 * Y + k = 3 * X - Y + k.
 * To ensure Y is the median, we need A <= Y and C >= Y.
 * Since A = Y - k, A <= Y is satisfied for any k >= 0.
 * Since C = 3 * X - Y + k, C >= Y is satisfied if 3 * X - Y + k >= Y,
 * which simplifies to 3 * X - 2 * Y + k >= 0, or k >= 2 * Y - 3 * X.
 * 
 * We can simply pick k = 0, so A = Y, B = Y, C = 3 * X - 2 * Y.
 * Wait, if we pick A = Y, B = Y, C = 3 * X - 2 * Y, the median is Y.
 * Let's check:
 * If 3*X - 2*Y >= Y, then sorted order is Y, Y, 3*X - 2*Y. Median is Y.
 * If 3*X - 2*Y < Y, then sorted order is 3*X - 2*Y, Y, Y. Median is Y.
 * This works perfectly!
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    long long A = Y;
    long long B = Y;
    long long C = 3 * X - 2 * Y;
    
    cout << A << " " << B << " " << C << "\n";
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