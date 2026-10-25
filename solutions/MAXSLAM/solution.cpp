#include <iostream>

/**
 * Problem Analysis:
 * Chef needs to reach a total of at least 25 Grand Slams.
 * Chef currently has X wins.
 * Each year, Chef wins 4 Grand Slams.
 * Let Y be the number of years.
 * We need: X + 4 * Y >= 25
 * 4 * Y >= 25 - X
 * Y >= (25 - X) / 4
 * Since Y must be an integer, Y = ceil((25 - X) / 4).
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b.
 * For (25 - X) / 4, this is (25 - X + 3) / 4.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long X;
    // The problem states the input is a single integer X.
    if (std::cin >> X) {
        long long needed = 25 - X;
        
        if (needed <= 0) {
            // Chef already has 25 or more wins
            std::cout << 0 << std::endl;
        } else {
            // Calculate ceiling of needed / 4
            // Formula: (numerator + denominator - 1) / denominator
            long long years = (needed + 3) / 4;
            std::cout << years << std::endl;
        }
    }

    return 0;
}