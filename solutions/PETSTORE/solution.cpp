#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob must end up with the exact same multiset of animals.
 * Let the total count of animal type 'x' be C(x).
 * If Alice takes k_x animals of type 'x', Bob must take C(x) - k_x animals.
 * For their multisets to be identical, Alice and Bob must have the same number 
 * of each animal type: k_x = C(x) - k_x, which implies 2 * k_x = C(x).
 * Therefore, C(x) must be even for all types 'x'.
 * 
 * Complexity:
 * Time: O(N) per test case to count frequencies.
 * Space: O(1) as the frequency array size is fixed at 101.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Since A_i is small (1 to 100), a frequency array is optimal.
    vector<int> counts(101, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a >= 1 && a <= 100) {
            counts[a]++;
        }
    }
    
    // Check if every animal type has an even count.
    bool possible = true;
    for (int i = 1; i <= 100; ++i) {
        if (counts[i] % 2 != 0) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}