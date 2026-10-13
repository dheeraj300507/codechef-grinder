# [AabBcCDd (AABBCCDD)](https://www.codechef.com/problems/AABBCCDD)

- **Difficulty Rating**: 972
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ containing both uppercase and lowercase English letters, we are allowed two operations:
1. Convert any uppercase letter to its lowercase equivalent.
2. Choose any lowercase letter and merge all its occurrences into another lowercase letter.

The goal is to maximize the total count of a single character after performing these operations.

## Intuition & Mathematical Observation
1. **Normalization**: Since we can convert any uppercase letter to lowercase, the case of the letters does not matter. We can treat 'A' and 'a' as the same character. We first count the frequency of each letter (a-z) in the string.
2. **Merging**: The second operation allows us to take all occurrences of one character and add them to another. To maximize the count of a single character, we should identify the two characters that appear most frequently in the string.
3. **Maximization**: By merging the second most frequent character into the most frequent one, we obtain a total count equal to the sum of the two highest frequencies. If the string contains only one type of character, the second frequency will be 0, which still holds true for our logic.

## Complexity Analysis
- **Time Complexity**: $O(N + \Sigma \log \Sigma)$, where $N$ is the length of the string and $\Sigma$ is the size of the alphabet (26). We iterate through the string once ($O(N)$) and sort the frequency array of constant size ($O(26 \log 26)$). Thus, the complexity is effectively **$O(N)$**.
- **Space Complexity**: **$O(1)$** (or $O(\Sigma)$), as we only use a fixed-size array of length 26 to store character frequencies regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * 1. Convert all uppercase letters to lowercase to normalize the string.
 * 2. Count the frequency of each character (a-z).
 * 3. Sort the frequencies in descending order.
 * 4. The maximum possible count for a single character is the sum of the 
 *    two largest frequencies, as we can merge the second most frequent 
 *    character into the most frequent one.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> freq(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else {
            freq[c - 'a']++;
        }
    }

    // Sort frequencies to find the two largest
    sort(freq.rbegin(), freq.rend());

    // The maximum score is the sum of the two most frequent characters.
    cout << freq[0] + freq[1] << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```