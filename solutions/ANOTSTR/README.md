# [Another String (ANOTSTR)](https://www.codechef.com/problems/ANOTSTR)

- **Difficulty Rating**: 1140
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given two binary strings $A$ and $B$ of length $N$. You are allowed to perform an operation where you choose two indices $i$ and $j$, swap the characters at these positions, and then flip both characters (i.e., '0' becomes '1' and '1' becomes '0'). The goal is to determine if it is possible to transform string $A$ into string $B$ using any number of these operations.

## Intuition & Mathematical Observation
To solve this problem, we analyze how the operation affects the properties of the string:

1.  **Effect on the count of '1's:**
    *   If we pick two '0's: They become '1's. The count of '1's increases by 2.
    *   If we pick two '1's: They become '0's. The count of '1's decreases by 2.
    *   If we pick one '0' and one '1': They swap and flip, resulting in one '0' and one '1'. The count of '1's remains unchanged.

2.  **The Invariant:**
    In all possible operations, the number of '1's in the string changes by either $+2$, $-2$, or $0$. This implies that the **parity** of the number of '1's in the string is an invariant. If the number of '1's in string $A$ and string $B$ have different parities, it is impossible to transform $A$ into $B$.

3.  **Sufficiency:**
    For strings of sufficient length ($N \ge 3$), the ability to swap and flip allows enough flexibility to reach any configuration that shares the same parity of '1's. Thus, the parity of the count of '1's is both a necessary and sufficient condition.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the strings. We iterate through each string once to count the number of '1's.
- **Space Complexity**: $O(N)$ to store the input strings.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation changes the count of '1's by +2, -2, or 0.
 * Therefore, the parity of the number of '1's is invariant.
 * If countA % 2 == countB % 2, it is possible to transform A to B.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA = 0;
    for (char c : A) if (c == '1') countA++;
    
    int countB = 0;
    for (char c : B) if (c == '1') countB++;

    // Check if the parity of the number of 1s is the same
    if (countA % 2 == countB % 2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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