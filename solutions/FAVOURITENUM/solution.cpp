#include <iostream>

using namespace std;

/**
 * Problem: FAVOURITENUM
 * Approach:
 * 1. Read the integer A.
 * 2. Check Alice's condition: (A % 2 == 0) && (A % 7 == 0).
 * 3. Check Bob's condition: (A % 2 != 0) && (A % 9 == 0).
 * 4. If neither, output "Charlie".
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

void solve() {
    int a;
    cin >> a;
    
    // Alice likes numbers which are even, and are a multiple of 7.
    if (a % 2 == 0 && a % 7 == 0) {
        cout << "Alice" << "\n";
    }
    // Bob likes numbers which are odd, and are a multiple of 9.
    else if (a % 2 != 0 && a % 9 == 0) {
        cout << "Bob" << "\n";
    }
    // Otherwise, Charlie takes it home.
    else {
        cout << "Charlie" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}