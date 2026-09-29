# [Non-Negative Product (NONNEGPROD)](https://www.codechef.com/problems/NONNEGPROD)

- **Difficulty Rating**: 948
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array of $N$ integers, determine the minimum number of elements that must be removed so that the product of the remaining elements is non-negative (i.e., $\ge 0$).

## Intuition & Mathematical Observation
The sign of the product of a set of numbers is determined by two factors:
1. **Presence of Zero**: If the array contains at least one `0`, the product is `0`, which is non-negative. In this case, we need to remove **0** elements.
2. **Count of Negative Numbers**: 
   - If there are no zeros, the product depends on the count of negative numbers.
   - If the count of negative numbers is **even**, the product is positive. We need to remove **0** elements.
   - If the count of negative numbers is **odd**, the product is negative. By removing exactly one negative number, the count becomes even, making the product positive. Thus, we need to remove **1** element.

**Conclusion:**
- If `has_zero == true` OR `negative_count % 2 == 0`, the answer is `0`.
- Otherwise, the answer is `1`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables (`negative_count`, `has_zero`, etc.) regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * The product of an array is non-negative if:
 * 1. There is at least one zero in the array (product becomes 0).
 * 2. The number of negative integers is even (product becomes positive).
 * 
 * If there are no zeros and the number of negative integers is odd, the product is negative.
 * In this case, removing exactly one negative integer will make the count of negative 
 * integers even, resulting in a non-negative product.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    int negative_count = 0;
    bool has_zero = false;
    
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            has_zero = true;
        } else if (a < 0) {
            negative_count++;
        }
    }
    
    if (has_zero) {
        // If there is a zero, the product is 0, which is non-negative.
        cout << 0 << "\n";
    } else {
        // If no zero, check if the count of negative numbers is even or odd.
        if (negative_count % 2 == 0) {
            // Even number of negatives results in a positive product.
            cout << 0 << "\n";
        } else {
            // Odd number of negatives results in a negative product.
            // Removing one negative number makes the count even.
            cout << 1 << "\n";
        }
    }
}

int main() {
    // Optimize standard I/O operations for speed
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