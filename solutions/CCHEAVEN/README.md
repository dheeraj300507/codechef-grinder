# [Chef in Heaven (CCHEAVEN)](https://www.codechef.com/problems/CCHEAVEN)

- **Difficulty Rating**: 1317
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef wants to know if he can go to heaven. He believes he can enter heaven if, at any point in his life (represented by a string of '0's and '1's), the number of "good years" (represented by '1') is at least 50% of the total years passed so far. Given a string $S$ of length $L$, we need to determine if there exists any prefix of length $L'$ ($1 \le L' \le L$) such that the count of '1's in that prefix is $\ge \frac{L'}{2}$.

## Intuition & Mathematical Observation
The problem asks us to check if there exists a prefix of length $L'$ such that:
$$\frac{\text{count of '1's}}{L'} \ge 0.5$$

To avoid floating-point precision issues, we can multiply both sides by $2 \times L'$:
$$2 \times (\text{count of '1's}) \ge L'$$

Since we need to check this condition for every possible prefix, we can iterate through the string once, maintaining a running count of '1's. At each index $i$ (where $L' = i + 1$), we check the inequality. If the condition is met at any point, we can immediately conclude "YES" and terminate the search for that test case. If we finish the loop without meeting the condition, the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(L)$ per test case, where $L$ is the length of the string. We perform a single pass over the string, and each operation inside the loop is $O(1)$.
- **Space Complexity**: $O(L)$ to store the input string. This is optimal as we must read the input.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to check if there exists any prefix of length L' (1 <= L' <= L)
 * such that the number of '1's in that prefix is >= 50% of L'.
 * 
 * Condition: good_years / L' >= 0.5  =>  2 * good_years >= L'
 */

void solve() {
    int L;
    if (!(cin >> L)) return;
    string S;
    cin >> S;

    int good_years = 0;
    bool possible = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years++;
        }
        
        // Current length L' is i + 1
        // Check if good_years / (i + 1) >= 0.5
        // Equivalent to 2 * good_years >= i + 1
        if (2 * good_years >= (i + 1)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```