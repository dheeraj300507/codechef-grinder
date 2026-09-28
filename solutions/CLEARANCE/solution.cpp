#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef pays for X t-shirts.
 * For every 2 t-shirts paid, he gets 1 free.
 * Number of free t-shirts = X / 2.
 * Total t-shirts = X + (X / 2).
 * 
 * Input Format:
 * The input contains a single integer X. There is no test case count T.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the single integer X directly as per the problem description
    if (cin >> X) {
        // Calculate total t-shirts
        // Since X is guaranteed to be even, X/2 is always an integer.
        int free_shirts = X / 2;
        int total_shirts = X + free_shirts;
        
        cout << total_shirts << endl;
    }

    return 0;
}