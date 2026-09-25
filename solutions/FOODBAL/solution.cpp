#include <iostream>
#include <cmath>
#include <algorithm>

/**
 * Problem: FOODBAL
 * The goal is to compare the absolute difference between fat and protein for two dishes.
 * D1 = |F1 - P1|
 * D2 = |F2 - P2|
 * 
 * Complexity: O(1) time, O(1) space.
 */

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f1, p1, f2, p2;
    
    // Read the four integers. The problem guarantees one line of input.
    if (cin >> f1 >> p1 >> f2 >> p2) {
        // Calculate absolute differences using std::abs
        int diff1 = std::abs(f1 - p1);
        int diff2 = std::abs(f2 - p2);

        // Compare and output the result
        if (diff1 < diff2) {
            cout << "First" << endl;
        } else if (diff2 < diff1) {
            cout << "Second" << endl;
        } else {
            cout << "Both" << endl;
        }
    }

    return 0;
}