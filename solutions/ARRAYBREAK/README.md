# [Break the elements (ARRAYBREAK)](https://www.codechef.com/problems/ARRAYBREAK)

- **Difficulty Rating**: 1191
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to make all elements of the array have the same parity (either all even or all odd). We are allowed to perform an operation where we pick an element $x$ and replace it with two integers $a$ and $b$ such that $a + b = x$. We want to find the minimum number of operations required to achieve the goal.

## Intuition & Mathematical Observation
To solve this, we analyze the parity properties of addition:
1. **Odd + Odd = Even**
2. **Even + Even = Even**
3. **Odd + Even = Odd**

**Goal 1: Make all elements Even**
To make an odd number even, we would need to split it into two numbers whose sum is odd. Based on the rules above, the only way to get an odd sum is (Odd + Even). However, this results in an odd number and an even number, meaning we haven't successfully converted the odd number into even numbers. Thus, it is impossible to make an odd number even through this operation. If the array contains any odd numbers, we cannot make the entire array even.

**Goal 2: Make all elements Odd**
To make an even number odd, we can split it into two odd numbers (Odd + Odd = Even). This takes exactly **1 operation** per even number. If we have existing odd numbers, we can keep them as they are and convert all even numbers into odd numbers.

**Conclusion:**
- If the array contains **no odd numbers**, the array is already all even. The cost is **0**.
- If the array contains **at least one odd number**, we can convert all even numbers into odd numbers by splitting each one once. The cost is equal to the **count of even numbers**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the array exactly once to count the parities.
- **Space Complexity**: $O(1)$ (excluding the input storage), as we only maintain two integer counters.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - If there are no odd numbers, the array is already all even (0 operations).
 * - If there are odd numbers, we can make all even numbers odd by splitting them.
 * - Each even number takes 1 operation to become two odd numbers.
 * - Thus, the answer is the count of even numbers if there is at least one odd number.
 */

void solve() {
    int n;
    cin >> n;
    int odd_count = 0;
    int even_count = 0;
    
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == 0) {
        // All are even, already same parity
        cout << 0 << "\n";
    } else {
        // We can make all even numbers odd by splitting them.
        // Each even number takes 1 operation to become two odd numbers.
        cout << even_count << "\n";
    }
}

int main() {
    // Optimize I/O operations
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