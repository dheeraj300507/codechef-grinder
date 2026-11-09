# [Sorted Substrings (SSUBSTR)](https://www.codechef.com/problems/SSUBSTR)

- **Difficulty Rating**: 1310
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string consisting of '0's and '1's, we want to partition the string into the minimum number of "sorted" substrings. A substring is considered sorted if it does not contain the pattern "10". In one operation, we can remove a sorted substring from the string. We need to find the minimum number of operations required to remove the entire string.

## Intuition & Mathematical Observation
A binary string is "sorted" if all '0's appear before all '1's (e.g., "000", "111", or "00111"). The presence of the pattern "10" is what makes a string unsorted.

1.  **The "10" Transition**: Every time a '1' is immediately followed by a '0', it signifies a point where the sorted order is broken.
2.  **Operation Logic**: Each time we encounter a "10" transition, we are forced to end a sorted substring and start a new one. 
3.  **Counting**: By counting the number of occurrences of the substring "10" in the string, we effectively count how many times the sorted property is violated. Each "10" transition requires a new operation to clear the remaining part of the string. Thus, the total number of operations required is exactly equal to the number of "10" occurrences in the string.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single linear scan through the string to count the "10" occurrences.
- **Space Complexity**: $O(N)$ to store the input string. (This can be optimized to $O(1)$ if reading character by character).

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * A binary string is sorted if it contains no "10" substring.
 * Each operation allows removing a sorted substring (0...0, 1...1, or 0...01...1).
 * Removing a sorted substring can eliminate one "10" transition.
 * The minimum number of operations is the count of occurrences where '1' is 
 * immediately followed by '0'.
 * 
 * Complexity: O(N) time per test case, O(N) space to store the string.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int count10 = 0;
    // Iterate through the string and count every occurrence of "10"
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            count10++;
        }
    }
    cout << count10 << "\n";
}

int main() {
    // Optimize I/O operations for competitive programming
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