#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each dish has exactly 4 ingredients.
 * Two dishes are similar if at least 2 ingredients are common.
 * Since the number of ingredients is very small (4 per dish), 
 * we can store the ingredients of the first dish in a set or 
 * simply iterate through the second dish and count matches.
 * 
 * Time Complexity: O(T * N * M) where T is test cases, N is ingredients per dish (4),
 * and M is string comparison cost. Given constraints, this is well within 1s.
 * Space Complexity: O(N) to store the ingredients of one dish.
 */

void solve() {
    vector<string> dish1(4);
    vector<string> dish2(4);
    
    for (int i = 0; i < 4; ++i) {
        cin >> dish1[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> dish2[i];
    }
    
    int common_count = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (dish1[i] == dish2[j]) {
                common_count++;
                break;
            }
        }
    }
    
    if (common_count >= 2) {
        cout << "similar" << "\n";
    } else {
        cout << "dissimilar" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}