# [Tanu and Head-bob (HEADBOB)](https://www.codechef.com/problems/HEADBOB)

- **Difficulty Rating**: 1065
- **Solved in**: 2 attempt(s)

## Problem Summary
Tanu is observing people's head movements to determine if they are Indian or not. We are given a string of gestures consisting of 'I' (Indian head-bob), 'Y' (Yes gesture), and 'N' (No gesture).
- If an 'I' is present, the person is **INDIAN**.
- If a 'Y' is present, the person is **NOT INDIAN**.
- If only 'N's are present, we are **NOT SURE** about their origin.

## Intuition & Mathematical Observation
The problem can be solved by scanning the string for specific characters. Since the presence of 'I' immediately confirms the person is Indian and 'Y' immediately confirms they are not, we can prioritize these checks:
1. **Priority 1:** If we encounter 'I', we stop and output "INDIAN".
2. **Priority 2:** If we encounter 'Y', we stop and output "NOT INDIAN".
3. **Default:** If we finish scanning the string and find neither 'I' nor 'Y' (meaning only 'N's were present), we output "NOT SURE".

Because the problem implies that 'I' and 'Y' are mutually exclusive in terms of determining the origin, a simple linear scan is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string at most once.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Logic:
 * - 'I' is the Indian head-bob. If found, the person is definitely INDIAN.
 * - 'Y' is the standard "Yes" gesture. If found, the person is NOT INDIAN.
 * - 'N' is the "No" gesture. If only 'N's are present, we cannot determine the origin (NOT SURE).
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    bool found_i = false;
    bool found_y = false;

    // Scan the string for the first occurrence of 'I' or 'Y'
    for (char c : s) {
        if (c == 'I') {
            found_i = true;
            break;
        } else if (c == 'Y') {
            found_y = true;
            break;
        }
    }

    // Determine result based on flags
    if (found_i) {
        cout << "INDIAN" << "\n";
    } else if (found_y) {
        cout << "NOT INDIAN" << "\n";
    } else {
        cout << "NOT SURE" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for faster execution
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