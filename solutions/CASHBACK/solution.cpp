#include <iostream>

/**
 * Problem Analysis:
 * The problem asks for the effective price of a cake.
 * Input: A single integer X (100 <= X <= 500).
 * Logic:
 * - If X >= 200, the customer gets 50 rupees back. Effective price = X - 50.
 * - If X < 200, no cashback. Effective price = X.
 * 
 * The previous attempt failed because it incorrectly assumed the input 
 * format included a number of test cases (t).
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    // Read the single integer X as specified in the problem format
    if (std::cin >> x) {
        if (x >= 200) {
            std::cout << (x - 50) << std::endl;
        } else {
            std::cout << x << std::endl;
        }
    }

    return 0;
}