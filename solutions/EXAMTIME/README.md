# [TCS Examination (EXAMTIME)](https://www.codechef.com/problems/EXAMTIME)

- **Difficulty Rating**: 1006
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the winner between two students, Dragon and Sloth, based on their scores in three subjects: DSA, TOC, and DM. The winner is decided by the following hierarchical criteria:
1. The student with the higher **total score** wins.
2. If total scores are equal, the student with the higher **DSA score** wins.
3. If DSA scores are also equal, the student with the higher **TOC score** wins.
4. If all the above are equal, the result is a **TIE**.

## Intuition & Mathematical Observation
The problem essentially requires a lexicographical comparison of two sets of attributes. We can define a "score profile" for each student as a tuple: `(Total, DSA, TOC)`. 

By comparing these tuples in the order specified, we can determine the winner. Since the criteria are strictly hierarchical, we can use nested `if-else` statements or compare the values directly. If the first elements (Total) are different, the winner is decided immediately. If they are equal, we move to the second element (DSA), and so on.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of arithmetic operations and comparisons regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the scores, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: TCS Examination
 * Logic:
 * We need to compare two students (Dragon and Sloth) based on a hierarchy of criteria:
 * 1. Total score (DSA + TOC + DM)
 * 2. DSA score
 * 3. TOC score
 * 
 * We can represent these criteria as a tuple (Total, DSA, TOC) and compare them lexicographically.
 */

void solve() {
    int d_dsa, d_toc, d_dm;
    int s_dsa, s_toc, s_dm;

    cin >> d_dsa >> d_toc >> d_dm;
    cin >> s_dsa >> s_toc >> s_dm;

    int d_total = d_dsa + d_toc + d_dm;
    int s_total = s_dsa + s_toc + s_dm;

    // Compare based on the criteria provided
    if (d_total > s_total) {
        cout << "DRAGON" << "\n";
    } else if (s_total > d_total) {
        cout << "SLOTH" << "\n";
    } else {
        // Total scores are tied, check DSA
        if (d_dsa > s_dsa) {
            cout << "DRAGON" << "\n";
        } else if (s_dsa > d_dsa) {
            cout << "SLOTH" << "\n";
        } else {
            // DSA scores are tied, check TOC
            if (d_toc > s_toc) {
                cout << "DRAGON" << "\n";
            } else if (s_toc > d_toc) {
                cout << "SLOTH" << "\n";
            } else {
                // Everything is tied
                cout << "TIE" << "\n";
            }
        }
    }
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
```