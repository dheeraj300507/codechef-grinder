#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string of length N consisting of 'R', 'G', and 'B'.
 * We want to make all characters in the string the same color.
 * To minimize the number of rooms to repaint, we should choose the color 
 * that already appears the most frequently in the string and repaint 
 * all other rooms to that color.
 * 
 * The number of rooms to repaint = Total rooms (N) - Maximum frequency of any color.
 * 
 * Time Complexity: O(N) per test case, where N is the number of rooms.
 * Space Complexity: O(N) to store the string, or O(1) if processed character by character.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int countR = 0;
    int countG = 0;
    int countB = 0;

    for (char c : s) {
        if (c == 'R') countR++;
        else if (c == 'G') countG++;
        else if (c == 'B') countB++;
    }

    // Find the maximum frequency among the three colors
    int maxFreq = max({countR, countG, countB});

    // The minimum number of rooms to repaint is total rooms minus the count of the most frequent color
    cout << (n - maxFreq) << "\n";
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