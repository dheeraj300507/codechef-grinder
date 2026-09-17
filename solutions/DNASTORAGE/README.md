# [DNA Storage (DNASTORAGE)](https://www.codechef.com/problems/DNASTORAGE)

- **Difficulty Rating**: 801
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem requires us to encode a binary string of even length $N$ into a DNA sequence. The encoding rules are based on pairs of bits:
- `00` maps to `A`
- `01` maps to `T`
- `10` maps to `C`
- `11` maps to `G`

We are given the length $N$ and the binary string, and we must output the resulting DNA sequence.

## Intuition & Mathematical Observation
Since the string length $N$ is guaranteed to be even, we can process the string by jumping two indices at a time. By iterating from $i = 0$ to $N-1$ with a step of 2, we can easily isolate each pair of bits (`s[i]` and `s[i+1]`). 

Using a simple conditional structure (or a map/lookup table), we can translate these pairs into their corresponding DNA characters. This approach ensures we visit every character exactly once, making it highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the binary string. We iterate through the string once, performing constant-time operations for each pair.
- **Space Complexity**: $O(N)$ to store the input string and the resulting DNA sequence.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DNA Storage
 * Approach:
 * The problem asks to map pairs of binary digits to specific characters:
 * "00" -> 'A', "01" -> 'T', "10" -> 'C', "11" -> 'G'
 * 
 * Since N is even, we iterate through the string with a step of 2,
 * extract the substring of length 2, and map it to the corresponding character.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    string result = "";
    for (int i = 0; i < n; i += 2) {
        string pair = s.substr(i, 2);
        if (pair == "00") {
            result += 'A';
        } else if (pair == "01") {
            result += 'T';
        } else if (pair == "10") {
            result += 'C';
        } else if (pair == "11") {
            result += 'G';
        }
    }
    cout << result << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```