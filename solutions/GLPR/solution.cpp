#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys the metal frame if Y <= 2 * X.
 * Otherwise, Chef buys the plastic frame.
 * 
 * Constraints:
 * 1 <= X, Y <= 2000
 * Since the maximum value is 2000, 2 * X will be at most 4000.
 * Standard 'int' is sufficient as it handles up to 2*10^9.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the 
    // input format description, but standard competitive programming practice 
    // often involves reading until EOF or a specific count. 
    // Given the format "The first and only line of input will contain...", 
    // we process the single line provided.
    
    long long X, Y;
    if (cin >> X >> Y) {
        if (Y <= 2 * X) {
            cout << "METAL" << "\n";
        } else {
            cout << "PLASTIC" << "\n";
        }
    }

    return 0;
}