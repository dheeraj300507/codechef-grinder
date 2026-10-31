#include <iostream>

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * To have exactly K fixed points:
 * 1. We choose K indices to be fixed (P[i] = i).
 * 2. The remaining (N - K) elements must form a derangement (no element i is at position i).
 * 
 * A derangement of size M exists if and only if M != 1.
 * - If M = 0: A derangement exists (the empty set).
 * - If M = 1: No derangement exists (the single element must be at its own position).
 * - If M >= 2: A derangement always exists.
 * 
 * Therefore, the condition is simply N - K != 1, which is equivalent to K != N - 1.
 */

int main() {
    // Optimize standard I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;
    while (t--) {
        int n, k;
        std::cin >> n >> k;

        // If N - K == 1, we are forced to have one extra fixed point.
        // Otherwise, it is always possible.
        if (k == n - 1) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

    return 0;
}