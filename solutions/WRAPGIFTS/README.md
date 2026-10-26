# [Christmas Gifts (WRAPGIFTS)](https://www.codechef.com/problems/WRAPGIFTS)

- **Difficulty Rating**: 574
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has 1000 square centimeters of wrapping paper. Given the dimensions (Height $H$, Length $L$, and Width $W$) of a rectangular gift box, calculate the maximum number of such gifts that can be completely wrapped using the available paper.

## Intuition & Mathematical Observation
The surface area of a rectangular prism (box) is calculated using the formula:
$$\text{Surface Area} = 2 \times (H \times L + L \times W + W \times H)$$

Since Chef has a fixed amount of paper (1000 $cm^2$), the number of gifts he can wrap is the total paper divided by the surface area of a single gift. Because we can only wrap *complete* gifts, we use integer division (which effectively performs the floor operation):
$$\text{Max Gifts} = \lfloor \frac{1000}{\text{Surface Area}} \rfloor$$

Given the constraints ($1 \le H, L, W \le 10$), the surface area will always be at least 6 and at most 600, ensuring the calculation is straightforward and fits within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the dimensions and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The surface area of a rectangular box with dimensions H, L, and W is given by:
 * Surface Area = 2 * (H*L + L*W + W*H)
 * 
 * Chef has a total of 1000 square centimeters of wrapping paper.
 * To find the maximum number of complete gifts, we divide the total area (1000)
 * by the surface area of one gift and take the floor of the result.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long h, l, w;
        cin >> h >> l >> w;

        // Calculate surface area of one gift
        // Formula: 2 * (HL + LW + WH)
        long long surface_area = 2 * (h * l + l * w + w * h);

        // Total paper available is 1000
        long long total_paper = 1000;

        // Calculate maximum number of gifts using integer division
        long long max_gifts = total_paper / surface_area;

        cout << max_gifts << "\n";
    }

    return 0;
}
```