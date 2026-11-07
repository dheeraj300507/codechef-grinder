# [Cool Name (CALPOWER)](https://www.codechef.com/problems/CALPOWER)

- **Difficulty Rating**: 1223
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, the "power" of the string is calculated as the sum of the products of each character's alphabetical position (where 'a'=1, 'b'=2, ..., 'z'=26) and its 1-based index in the string. We are allowed to rearrange the characters of the string in any order. The goal is to find the maximum possible power of the string.

## Intuition & Mathematical Observation
The power of the string is defined by the formula:
$$\text{Power} = \sum_{i=1}^{|S|} (i \times \text{ord}(S_i))$$
where $\text{ord}(S_i)$ is the alphabetical position of the character at index $i$.

To maximize this sum, we apply the **Rearrangement Inequality**. This principle states that for two sequences of numbers, the sum of their products is maximized when both sequences are sorted in the same order (i.e., the largest values are multiplied together).

1. The indices $i$ are fixed as $\{1, 2, 3, \dots, |S|\}$.
2. To maximize the sum, we must pair the smallest alphabetical values with the smallest indices and the largest alphabetical values with the largest indices.
3. Therefore, we sort the string $S$ in non-decreasing alphabetical order. Once sorted, the character at index $i$ (1-based) will be the $i$-th smallest character, ensuring the highest values are multiplied by the highest indices.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, where $N$ is the length of the string. This is dominated by the sorting step. Given $N \le 100$ and $T \le 60$, this is highly efficient.
- **Space Complexity**: $O(N)$ to store the string characters.

## Solution Code

```cpp
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
```