# [Speed Limit Test (SPEEDTEST)](https://www.codechef.com/problems/SPEEDTEST)

- **Difficulty Rating**: 718
- **Solved in**: 2 attempt(s)

## Problem Summary
Alice covers a distance $A$ in $X$ hours, and Bob covers a distance $B$ in $Y$ hours. We need to determine who is traveling faster. If Alice's speed is greater, output "ALICE"; if Bob's speed is greater, output "BOB"; if their speeds are equal, output "EQUAL".

## Intuition & Mathematical Observation
The speed of a person is calculated as $\text{distance} / \text{time}$. Therefore:
- Alice's speed = $A / X$
- Bob's speed = $B / Y$

To compare these two fractions without using floating-point numbers (which can lead to precision errors), we use **cross-multiplication**. Instead of comparing $\frac{A}{X}$ and $\frac{B}{Y}$, we compare $A \times Y$ and $B \times X$:
- If $A \times Y > B \times X$, then $\frac{A}{X} > \frac{B}{Y}$ (Alice is faster).
- If $A \times Y < B \times X$, then $\frac{A}{X} < \frac{B}{Y}$ (Bob is faster).
- If $A \times Y = B \times X$, then $\frac{A}{X} = \frac{B}{Y}$ (Speeds are equal).

Using `long long` in C++ ensures that the multiplication does not overflow, as the input constraints are small enough for standard integer types, but `long long` is safer practice.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and results.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Alice speed = A / X
 * Bob speed = B / Y
 * To compare A/X and B/Y, compare A*Y and B*X to avoid floating point issues.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, x, b, y;
        cin >> a >> x >> b >> y;

        // Compare speeds using cross-multiplication: (a/x) vs (b/y) => a*y vs b*x
        long long alice_val = a * y;
        long long bob_val = b * x;

        if (alice_val > bob_val) {
            cout << "ALICE" << "\n";
        } else if (bob_val > alice_val) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}
```