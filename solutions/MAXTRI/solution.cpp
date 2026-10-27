#include <iostream>

/**
 * Problem Analysis:
 * We have sticks of lengths 1, 2, ..., N.
 * A triangle is non-degenerate if A + B > C, where C is the max side.
 * To maximize perimeter A + B + C, we pick the largest available sticks:
 * C = N, B = N-1, A = N-2.
 * Condition: (N-1) + (N-2) > N  => 2N - 3 > N => N > 3.
 * 
 * If N < 4, no such triangle exists.
 * If N >= 4, the maximum perimeter is N + (N-1) + (N-2) = 3N - 3.
 */

void solve() {
    long long N;
    if (!(std::cin >> N)) return;

    // The smallest N that allows a triangle is 4 (sides 2, 3, 4: 2+3 > 4).
    // For N=3, sides are 1, 2, 3: 1+2 = 3 (degenerate).
    if (N < 4) {
        std::cout << -1 << "\n";
    } else {
        // 3N - 3 can be up to 3 * 10^8 - 3, which fits in a standard 32-bit signed int,
        // but using long long is safer for competitive programming.
        std::cout << (3 * N - 3) << "\n";
    }
}

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    if (!(std::cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}