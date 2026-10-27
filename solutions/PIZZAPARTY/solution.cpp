#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Chef is a boy, so total boys = A + 1.
 * - Total girls = B.
 * - Each boy eats 4 slices, each girl eats 3 slices.
 * - Total slices needed = (A + 1) * 4 + B * 3.
 * - Each pizza has 8 slices.
 * - Number of pizzas needed = ceil(Total slices / 8).
 * - Using integer arithmetic, ceil(x / y) = (x + y - 1) / y.
 * 
 * Input Format:
 * - The input contains exactly one line with two integers A and B.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read A and B directly as there is only one test case
    if (cin >> A >> B) {
        long long total_boys = A + 1;
        long long total_girls = B;
        long long total_slices = (total_boys * 4) + (total_girls * 3);

        // Calculate ceiling division: (total_slices + 8 - 1) / 8
        long long pizzas_needed = (total_slices + 7) / 8;

        cout << pizzas_needed << endl;
    }

    return 0;
}