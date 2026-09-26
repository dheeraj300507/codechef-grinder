#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N types of colors, with A_i balls of color i.
 * We need to place these balls into boxes such that no box contains two balls of the same color.
 * 
 * Let M be the maximum number of balls of any single color, i.e., M = max(A_1, A_2, ..., A_N).
 * If we have M balls of a specific color, we must have at least M boxes to ensure that 
 * each of those M balls is in a different box.
 * 
 * Conversely, if we have M boxes, we can always distribute the balls such that no box 
 * contains two balls of the same color. We can do this by placing the balls of each color 
 * into distinct boxes. Since no color has more than M balls, we will never run out of 
 * boxes for any color.
 * 
 * Therefore, the minimum number of boxes required is exactly the maximum value among A_i.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        long long max_balls = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            if (a > max_balls) {
                max_balls = a;
            }
        }
        
        cout << max_balls << "\n";
    }
    
    return 0;
}