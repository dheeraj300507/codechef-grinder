#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 * Also, since Alice must give cookies to Bob, x must be greater than 0.
 * Given A > B, A - B is always > 0.
 * Thus, the condition is simply: (A - B) % 2 == 0.
 * If true, output (A - B) / 2.
 * Otherwise, output -1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but the instructions mention handling multiple test cases if applicable.
    // Given the constraints and format, we read A and B.
    long long A, B;
    if (!(cin >> A >> B)) return 0;

    if ((A - B) % 2 == 0) {
        cout << (A - B) / 2 << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}