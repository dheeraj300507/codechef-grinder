#include <iostream>
#include <cmath>
#include <algorithm>

/**
 * Problem Analysis:
 * We are given two ranks X and Y. We need to find the number of teams 
 * strictly between them.
 * 
 * The number of integers strictly between X and Y is |X - Y| - 1.
 * 
 * Input Format:
 * The first and only line contains 2 integers X and Y.
 * There is no test case count T.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long x, y;
    if (std::cin >> x >> y) {
        // Calculate the absolute difference and subtract 1
        // Example: 1 and 5 -> |1 - 5| - 1 = 4 - 1 = 3
        // Example: 2 and 1 -> |2 - 1| - 1 = 1 - 1 = 0
        long long diff = std::abs(x - y) - 1;
        
        std::cout << diff << std::endl;
    }

    return 0;
}