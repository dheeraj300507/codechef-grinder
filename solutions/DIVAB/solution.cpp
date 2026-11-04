#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need the smallest integer X such that:
 * 1. X >= N
 * 2. X % A == 0
 * 3. X % B != 0
 * 
 * First, find the smallest multiple of A that is >= N.
 * Let this be X = ceil(N / A) * A.
 * In integer arithmetic, this is:
 * X = ((N + A - 1) / A) * A
 * 
 * If A is divisible by B, then any multiple of A is also a multiple of B.
 * In this case, no such number exists, so output -1.
 * 
 * If X % B != 0, then X is our answer.
 * If X % B == 0, we need to find the next multiple of A, which is X + A.
 * Since A is not divisible by B, (X + A) % B = (X % B + A % B) % B = (0 + A % B) % B = A % B.
 * Since A % B != 0, (X + A) % B != 0.
 * Thus, X + A will always satisfy the condition if A is not divisible by B.
 */

void solve() {
    long long A, B, N;
    cin >> A >> B >> N;

    // If A is a multiple of B, any multiple of A is also a multiple of B.
    // Therefore, no number can be divisible by A and NOT divisible by B.
    if (A % B == 0) {
        cout << -1 << "\n";
        return;
    }

    // Find the smallest multiple of A that is >= N
    long long X = ((N + A - 1) / A) * A;

    // If X is not divisible by B, it's our answer.
    if (X % B != 0) {
        cout << X << "\n";
    } else {
        // Otherwise, the next multiple of A (X + A) will work
        // because A is not divisible by B.
        cout << X + A << "\n";
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