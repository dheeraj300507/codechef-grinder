# [Make A and B equal (EQUALISE)](https://www.codechef.com/problems/EQUALISE)

- **Difficulty Rating**: 851
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we are allowed to multiply either number by $2$ any number of times. The goal is to determine if it is possible to make $A$ and $B$ equal by applying this operation.

## Intuition & Mathematical Observation
The operation allows us to transform $A$ into $A \times 2^x$ and $B$ into $B \times 2^y$ for any non-negative integers $x$ and $y$. 

To determine if they can be made equal:
1. Assume without loss of generality that $A \le B$.
2. Since we can only increase the numbers by powers of 2, if $A$ is smaller than $B$, we should repeatedly multiply $A$ by $2$.
3. If at any point $A$ becomes equal to $B$, the answer is **YES**.
4. If $A$ exceeds $B$ without ever being equal to it, it is impossible to make them equal, because any further multiplication will only increase the gap. Thus, the answer is **NO**.

This approach works because the operation is monotonic; we are essentially checking if $B$ is a multiple of $A$ where the quotient is a power of 2.

## Complexity Analysis
- **Time Complexity**: $O(\log(\max(A, B)))$ per test case. Since we multiply by 2 in each step, the loop runs at most logarithmic times relative to the magnitude of the larger number.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We can multiply either by 2 any number of times.
 * This means we can transform A into A * 2^x and B into B * 2^y.
 * We want to check if there exist non-negative integers x, y such that A * 2^x = B * 2^y.
 * 
 * This is equivalent to checking if one number can be transformed into the other.
 * Without loss of generality, assume A <= B.
 * We can multiply A by 2 repeatedly until it is either equal to B or exceeds B.
 * If it becomes equal to B, the answer is YES.
 * If it exceeds B, we can never make them equal because multiplying B by 2 
 * would only make the gap larger.
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // Ensure A is the smaller number
    if (A > B) {
        swap(A, B);
    }

    // Keep multiplying the smaller number by 2 until it reaches or exceeds the larger
    while (A < B) {
        A *= 2;
    }

    if (A == B) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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