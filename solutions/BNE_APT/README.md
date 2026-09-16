# [Bone Appetit (BNE_APT)](https://www.codechef.com/problems/BNE_APT)

- **Difficulty Rating**: 280
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total number of treats required for a party. We are given:
- $N$: The number of bone treats.
- $M$: The number of blood treats.
- $X$: The amount of treats per bone.
- $Y$: The amount of treats per blood.

We need to output the total number of treats, which is the sum of the treats from bones ($N \times X$) and the treats from blood ($M \times Y$).

## Intuition & Mathematical Observation
The problem is a straightforward application of basic arithmetic. Since we are given the quantity of each type of treat and the value per unit, the total is simply the sum of two products:
$$\text{Total} = (N \times X) + (M \times Y)$$

Given the constraints ($N, M \le 100$ and $X, Y \le 1000$), the maximum possible result is $200,000$. This value fits well within a standard 32-bit integer (`int`), though using `long long` is a good habit in competitive programming to prevent potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The calculation involves a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Bone Appetit
 * The total number of treats is the sum of treats from "Bones" and "Blood".
 * Total = (N * X) + (M * Y)
 * 
 * Constraints:
 * N, M <= 100
 * X, Y <= 1000
 * Maximum possible value = (100 * 1000) + (100 * 1000) = 200,000
 * This fits comfortably within a standard 32-bit integer, but we use long long 
 * for safety and best practices in competitive programming.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    long long X, Y;

    // Reading the input as per the problem description
    if (!(cin >> N >> M)) return 0;
    if (!(cin >> X >> Y)) return 0;

    // Calculating the total treats
    long long total_treats = (N * X) + (M * Y);

    // Output the result
    cout << total_treats << "\n";

    return 0;
}
```