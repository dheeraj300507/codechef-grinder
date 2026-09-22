#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef pays 100 rupees for items worth X rupees.
 * The change to be received is 100 - X.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X <= 100
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change: 100 - X
        int change = 100 - x;
        
        cout << change << "\n";
    }
    
    return 0;
}