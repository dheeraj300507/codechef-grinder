#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Height of Rationals
 * The height of a fraction a/b is defined as max(a, b).
 * Given the constraints 1 <= a, b <= 100, we simply read two integers
 * and output the maximum of the two.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    // The problem statement implies a single line of input per test case.
    // Based on standard competitive programming formats, we read until EOF
    // or as specified. Since the problem description doesn't explicitly 
    // mention a number of test cases 't', we handle the single input provided.
    if (cin >> a >> b) {
        cout << max(a, b) << "\n";
    }

    return 0;
}