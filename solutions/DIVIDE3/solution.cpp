#include <iostream>

/**
 * Problem Analysis:
 * We have N toffees to be divided among 3 friends.
 * Let the number of toffees given to the three friends be a, b, and c.
 * We have a + b + c = N.
 * We want to minimize (max(a, b, c) - min(a, b, c)).
 * 
 * By the division algorithm, N = 3 * q + r, where r is 0, 1, or 2.
 * - If r = 0: We can give each friend q toffees. Imbalance = q - q = 0.
 * - If r = 1: We can give friends q, q, and q+1 toffees. Imbalance = (q+1) - q = 1.
 * - If r = 2: We can give friends q, q+1, and q+1 toffees. Imbalance = (q+1) - q = 1.
 * 
 * Thus, if N is divisible by 3, the answer is 0. Otherwise, the answer is 1.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (std::cin >> n) {
        if (n % 3 == 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
    
    return 0;
}