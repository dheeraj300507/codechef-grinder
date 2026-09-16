#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have G girls and B boys, where B > G.
 * Each team consists of exactly 1 girl and 1 boy.
 * To maximize the number of teams, we pair each girl with one boy.
 * Since there are G girls, we can form at most G teams.
 * Each team uses 1 boy, so G boys are used.
 * The number of boys remaining is B - G.
 * Since we want to minimize the number of boys who cannot participate, 
 * and we are given B > G, the minimum number of boys left is exactly B - G.
 * 
 * Complexity:
 * Time Complexity: O(T), where T is the number of test cases.
 * Space Complexity: O(1), as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long g, b;
        cin >> g >> b;
        
        // The number of boys who cannot participate is the total boys minus the number of girls
        // (since each girl can form one team with one boy).
        long long result = b - g;
        
        cout << result << "\n";
    }

    return 0;
}