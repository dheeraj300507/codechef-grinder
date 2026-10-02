#include <iostream>

/**
 * Problem Analysis:
 * Chef bakes a cake every day from today (X) until the 24th of December.
 * The number of days from X to 24 inclusive is calculated as:
 * (24 - X) + 1
 * 
 * Constraints: 1 <= X <= 24.
 * The input format specifies a single integer X, not multiple test cases.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    // Read the single integer X directly as per the problem statement
    if (std::cin >> X) {
        // Calculate the number of cakes: 24 - X + 1
        int result = 25 - X;
        
        std::cout << result << std::endl;
    }

    return 0;
}