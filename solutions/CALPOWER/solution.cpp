#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The power of a string is defined as sum_{i=1 to |S|} (i * ord(S_i)).
 * To maximize this sum, we want the largest ord(S_i) values to be multiplied 
 * by the largest indices (i).
 * 
 * Since the indices i range from 1 to |S|, we should sort the characters 
 * of the string in non-decreasing order of their alphabetical position.
 * This way, the smallest character gets index 1, the next smallest gets 2, 
 * and the largest character gets index |S|.
 * 
 * Complexity:
 * Sorting takes O(N log N) where N is the length of the string.
 * Calculating the sum takes O(N).
 * Given N <= 100 and T <= 60, this approach is well within the time limits.
 */

void solve() {
    string s;
    cin >> s;
    
    // Sort the string to ensure characters are in non-decreasing order
    sort(s.begin(), s.end());
    
    long long total_power = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        // ord(S_i) is (s[i] - 'a' + 1)
        // index is (i + 1)
        int ord = s[i] - 'a' + 1;
        total_power += (long long)(i + 1) * ord;
    }
    
    cout << total_power << "\n";
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