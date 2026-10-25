# [Bear and Ladder (BRLADDER)](https://www.codechef.com/problems/BRLADDER)

- **Difficulty Rating**: 999
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a direct road exists between two given integers $a$ and $b$ in a specific infinite ladder structure. The ladder is defined by two types of connections:
1. Vertical rungs connect $(2i+1)$ and $(2i+2)$ for all $i \ge 0$ (e.g., 1-2, 3-4, 5-6).
2. Side rails connect consecutive odd numbers $(2i+1, 2i+3)$ and consecutive even numbers $(2i+2, 2i+4)$ for all $i \ge 0$ (e.g., 1-3, 2-4, 3-5).

Given $Q$ queries, we must output "YES" if a connection exists between $a$ and $b$, and "NO" otherwise.

## Intuition & Mathematical Observation
By analyzing the connections, we can categorize the relationship between any two numbers $a$ and $b$ based on their absolute difference:

1. **Difference of 1 ($|a - b| = 1$):**
   - These are vertical rungs. A connection exists if the smaller number is odd. For example, (1, 2) is connected because 1 is odd, but (2, 3) is not connected because the smaller number (2) is even.
   - Condition: `abs(a - b) == 1 && min(a, b) % 2 != 0`.

2. **Difference of 2 ($|a - b| = 2$):**
   - These are side rails. A connection exists between any two odd numbers that differ by 2, or any two even numbers that differ by 2.
   - Condition: `abs(a - b) == 2`.

3. **All other cases:**
   - No direct road exists between numbers with a difference other than 1 or 2.

## Complexity Analysis
- **Time Complexity**: $O(Q)$, where $Q$ is the number of queries. Each query is processed in $O(1)$ time using simple arithmetic checks.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform calculations.

## Solution Code

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * 1. Roads exist between (2i+1, 2i+2) for i >= 0.
 *    This implies if |a - b| == 1, they are connected if min(a, b) is odd.
 * 2. Roads exist between consecutive odd numbers (1-3, 3-5, ...) 
 *    and consecutive even numbers (2-4, 4-6, ...).
 *    This implies if |a - b| == 2, they are always connected.
 * 
 * Complexity: O(Q) time, O(1) space.
 */

void solve() {
    long long a, b;
    if (!(cin >> a >> b)) return;

    long long diff = abs(a - b);
    long long mn = min(a, b);

    if (diff == 1) {
        // Road exists if the smaller number is odd (1-2, 3-4, 5-6...)
        if (mn % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else if (diff == 2) {
        // Road exists between consecutive odds or consecutive evens
        cout << "YES" << "\n";
    } else {
        // No other roads exist
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }

    return 0;
}
```