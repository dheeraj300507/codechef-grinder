# [Similar Dishes (SIMDISH)](https://www.codechef.com/problems/SIMDISH)

- **Difficulty Rating**: 1142
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two dishes, each consisting of exactly 4 ingredients, determine if they are "similar". Two dishes are considered similar if they share at least 2 common ingredients.

## Intuition & Mathematical Observation
Since the number of ingredients per dish is very small (fixed at 4), we do not need complex data structures like Hash Maps or advanced algorithms. 

1. **Storage**: We can store the ingredients of the first dish in a `vector<string>` or an array.
2. **Comparison**: For every ingredient in the second dish, we iterate through the first dish to check for a match.
3. **Counting**: We maintain a counter `common_count`. If an ingredient from the second dish is found in the first, we increment the counter and move to the next ingredient in the second dish (to avoid double counting).
4. **Decision**: After checking all ingredients, if `common_count >= 2`, the dishes are "similar"; otherwise, they are "dissimilar".

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2 \times M)$, where $T$ is the number of test cases, $N$ is the number of ingredients per dish (4), and $M$ is the average length of the ingredient strings. Since $N$ is constant (4), this simplifies to $O(T \times M)$, which is extremely efficient and well within the 1-second time limit.
- **Space Complexity**: $O(N)$, as we only store the 4 ingredients of the first dish in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each dish has exactly 4 ingredients.
 * Two dishes are similar if at least 2 ingredients are common.
 * Since the number of ingredients is very small (4 per dish), 
 * we can store the ingredients of the first dish in a set or 
 * simply iterate through the second dish and count matches.
 */

void solve() {
    vector<string> dish1(4);
    vector<string> dish2(4);
    
    // Read ingredients for both dishes
    for (int i = 0; i < 4; ++i) cin >> dish1[i];
    for (int i = 0; i < 4; ++i) cin >> dish2[i];
    
    int common_count = 0;
    // Compare each ingredient of dish2 with all ingredients of dish1
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (dish1[i] == dish2[j]) {
                common_count++;
                break; // Found a match, move to next ingredient in dish2
            }
        }
    }
    
    // Check similarity condition
    if (common_count >= 2) {
        cout << "similar" << "\n";
    } else {
        cout << "dissimilar" << "\n";
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