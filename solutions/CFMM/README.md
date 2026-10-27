# [Making a Meal (CFMM)](https://www.codechef.com/problems/CFMM)

- **Difficulty Rating**: 1214
- **Solved in**: 2 attempt(s)

## Problem Summary
Given $N$ strings, we need to determine the maximum number of times the word **"codechef"** can be formed using the characters available across all the provided strings. Each character from the input strings can be used only once.

## Intuition & Mathematical Observation
To form one instance of the word "codechef", we require the following character counts:
- **c**: 2
- **o**: 1
- **d**: 1
- **e**: 2
- **h**: 1
- **f**: 1

**Strategy:**
1. Aggregate the total frequency of every character ('a' through 'z') present in all $N$ input strings.
2. Calculate how many times each required character can satisfy the "codechef" requirement:
   - For 'c' and 'e', divide their total count by 2 (since we need two of each).
   - For 'o', 'd', 'h', and 'f', use their total count as is (since we need one of each).
3. The maximum number of "codechef" strings we can form is limited by the "bottleneck" character—the character that allows for the minimum number of complete words. Therefore, the answer is the minimum value among the calculated counts.

## Complexity Analysis
- **Time Complexity**: $O(S)$, where $S$ is the total number of characters across all strings in a test case. Since the constraints are small (typically $\sum |S| \le 1000$), this approach is highly efficient.
- **Space Complexity**: $O(1)$, as we use a fixed-size array of size 26 to store character frequencies, regardless of the input size.

## Solution Code

```cpp
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
```