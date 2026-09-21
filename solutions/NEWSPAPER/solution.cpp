#include <iostream>

/**
 * Problem Analysis:
 * The newspaper has 10 pages (1 to 10).
 * The last 3 pages are 8, 9, and 10.
 * Given 1 <= X <= 10, the condition "last 3 pages" is satisfied if X >= 8.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize standard I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    if (std::cin >> X) {
        // Check if the page is 8, 9, or 10
        if (X >= 8) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}