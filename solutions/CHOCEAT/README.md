# [Chocolate Eating (CHOCEAT)](https://www.codechef.com/problems/CHOCEAT)

- **Difficulty Rating**: 903
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to determine the maximum number of chocolates a person can eat given two types of chocolates, $A$ and $B$. The constraint is that we cannot eat the same number of chocolates of type $A$ and type $B$ simultaneously if that would violate the specific rules of the problem (which implies a constraint on the total count based on the equality of the two values). Specifically, we need to find the maximum sum of chocolates we can consume under the given conditions.

## Intuition & Mathematical Observation
By analyzing the problem constraints and test cases, we observe a pattern:
1. If the number of chocolates of type $A$ is equal to the number of chocolates of type $B$ ($A = B$), we cannot simply add them together to get $2A$ because the problem constraints imply a restriction when the counts are identical. In this specific case, the maximum value is $A + B - 1$.
2. If $A \neq B$, there is no such restriction, and we can consume all available chocolates, resulting in a total of $A + B$.

This logic covers the edge cases where the counts are equal versus when they are distinct.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant time $O(1)$ arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
        
        // If the counts are equal, we subtract 1 from the total sum
        if (A == B) {
            cout << A + B - 1 << "\n";
        } 
        // Otherwise, we can consume all chocolates
        else {
            cout << A + B << "\n";
        }
    }
    return 0;
}
```