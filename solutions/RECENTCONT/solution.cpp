#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Recent contest problems
 * Approach: Iterate through the list of contest codes and maintain two counters.
 * Time Complexity: O(N) per test case, where N is the number of problems.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        int start38_count = 0;
        int ltime108_count = 0;
        
        for (int i = 0; i < n; ++i) {
            string code;
            cin >> code;
            
            if (code == "START38") {
                start38_count++;
            } else if (code == "LTIME108") {
                ltime108_count++;
            }
        }
        
        cout << start38_count << " " << ltime108_count << "\n";
    }
    
    return 0;
}