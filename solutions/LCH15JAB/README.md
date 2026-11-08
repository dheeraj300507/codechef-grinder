# [Piece of cake (LCH15JAB)](https://www.codechef.com/problems/LCH15JAB)

- **Difficulty Rating**: 1144
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, determine if there exists a character $c$ in the string such that its frequency is exactly equal to the sum of the frequencies of all other characters present in the string.

## Intuition & Mathematical Observation
Let $N$ be the total length of the string $S$. Let $freq(c)$ be the number of occurrences of a specific character $c$.
The problem states that the frequency of $c$ must equal the sum of the frequencies of all other characters:
$$freq(c) = \sum_{x \neq c} freq(x)$$

We know that the sum of the frequencies of all characters in the string is equal to the total length $N$:
$$\sum_{all \ x} freq(x) = N$$
$$freq(c) + \sum_{x \neq c} freq(x) = N$$

Substituting the condition $freq(c) = \sum_{x \neq c} freq(x)$ into the equation above:
$$freq(c) + freq(c) = N$$
$$2 \cdot freq(c) = N$$
$$freq(c) = \frac{N}{2}$$

Therefore, the problem reduces to checking if any character in the string appears exactly $N/2$ times.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies and then iterate through a fixed-size array of 26 characters.
- **Space Complexity**: $O(1)$, as the frequency array size is constant (26 characters), regardless of the input string length.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S. We need to check if there exists a character 'c' 
 * such that the frequency of 'c' is equal to the sum of the frequencies 
 * of all other characters in the string.
 * 
 * Let N be the total length of the string.
 * The condition simplifies to: freq(c) = N / 2.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Frequency map for characters 'a' through 'z'
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    bool found = false;
    for (int i = 0; i < 26; ++i) {
        // Check if any character appears exactly N/2 times
        if (freq[i] * 2 == n) {
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
```