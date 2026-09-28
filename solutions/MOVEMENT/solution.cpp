#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Starting at (0, 0):
 * 1. Move A units along positive X: (A, 0)
 * 2. Move B units along positive Y: (A, B)
 * 3. Move C units along negative X: (A - C, B)
 * 4. Move D units along negative Y: (A - C, B - D)
 * 
 * Final position: (A - C, B - D)
 * Constraints are small (1 to 10), so standard int is sufficient.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, D;
    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves reading until EOF 
    // or handling a test case count. Given the description, we read the 4 integers.
    if (cin >> A >> B >> C >> D) {
        int final_x = A - C;
        int final_y = B - D;
        cout << final_x << " " << final_y << "\n";
    }

    return 0;
}