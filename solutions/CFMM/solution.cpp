#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * To form the word "codechef", we need:
 * c: 2, o: 1, d: 1, e: 2, h: 1, f: 1
 * 
 * We count the total occurrences of each character across all input strings.
 * The number of "codechef" strings we can form is:
 * min(count['c']/2, count['o']/1, count['d']/1, count['e']/2, count['h']/1, count['f']/1)
 * 
 * Complexity: O(Total characters), which is at most 1000 per test case.
 * This is well within the time limits.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a fixed-size array for character counts (a-z)
    int counts[26] = {0};
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                counts[c - 'a']++;
            }
        }
    }
    
    // Requirements for one "codechef"
    // c: 2, o: 1, d: 1, e: 2, h: 1, f: 1
    int c = counts['c' - 'a'] / 2;
    int o = counts['o' - 'a'];
    int d = counts['d' - 'a'];
    int e = counts['e' - 'a'] / 2;
    int h = counts['h' - 'a'];
    int f = counts['f' - 'a'];
    
    int ans = min({c, o, d, e, h, f});
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}