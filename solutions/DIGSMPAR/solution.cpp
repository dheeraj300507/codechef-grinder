#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the smallest integer X > N such that digitSum(X) parity != digitSum(N) parity.
 * Since N < 10^9, the digit sum is relatively small (max digit sum for 999,999,999 is 81).
 * The parity of the digit sum changes very frequently as we increment N.
 * In the worst case, we only need to check a few consecutive integers to find one with a different parity.
 * A simple loop incrementing N and checking the parity of the digit sum will be highly efficient.
 */

// Function to calculate the sum of digits of a number
int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    // Increment x until the parity of its digit sum is different from n's digit sum
    while (true) {
        if ((getDigitSum(x) % 2) != targetParity) {
            cout << x << "\n";
            break;
        }
        x++;
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}