#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * The product of an array is non-negative if:
 * 1. There is at least one zero in the array (product becomes 0).
 * 2. The number of negative integers is even (product becomes positive).
 * 
 * If there are no zeros and the number of negative integers is odd, the product is negative.
 * In this case, removing exactly one negative integer will make the count of negative 
 * integers even, resulting in a non-negative product.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    int negative_count = 0;
    bool has_zero = false;
    
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            has_zero = true;
        } else if (a < 0) {
            negative_count++;
        }
    }
    
    if (has_zero) {
        // If there is a zero, the product is 0, which is non-negative.
        cout << 0 << "\n";
    } else {
        // If no zero, check if the count of negative numbers is even or odd.
        if (negative_count % 2 == 0) {
            // Even number of negatives results in a positive product.
            cout << 0 << "\n";
        } else {
            // Odd number of negatives results in a negative product.
            // Removing one negative number makes the count even.
            cout << 1 << "\n";
        }
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}