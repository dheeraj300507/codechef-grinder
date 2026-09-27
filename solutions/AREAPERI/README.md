# [Area OR Perimeter (AREAPERI)](https://www.codechef.com/problems/AREAPERI)

- **Difficulty Rating**: 858
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the length ($L$) and breadth ($B$) of a rectangle, calculate its area and perimeter. Compare the two values:
1. If the area is greater than the perimeter, print "Area" followed by the area.
2. If the perimeter is greater than the area, print "Peri" followed by the perimeter.
3. If they are equal, print "Eq" followed by the value.

## Intuition & Mathematical Observation
The problem is a direct application of geometry formulas:
*   **Area** = $L \times B$
*   **Perimeter** = $2 \times (L + B)$

By calculating both values using the provided inputs, we can use simple conditional (`if-else`) statements to determine which value is larger or if they are equal. Since the constraints for $L$ and $B$ are up to 1000, the maximum area is $1,000,000$ and the maximum perimeter is $4,000$, both of which comfortably fit within a standard 32-bit integer. However, using `long long` is a safe practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the dimensions and the calculated results, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Area OR Perimeter
 * Logic:
 * Area = L * B
 * Perimeter = 2 * (L + B)
 * Compare Area and Perimeter and output accordingly.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, B;
    
    // Read length and breadth
    if (!(cin >> L >> B)) return 0;

    long long area = L * B;
    long long peri = 2 * (L + B);

    // Compare and output based on problem requirements
    if (area > peri) {
        cout << "Area" << "\n";
        cout << area << "\n";
    } else if (peri > area) {
        cout << "Peri" << "\n";
        cout << peri << "\n";
    } else {
        // If equal, print "Eq" and the value
        cout << "Eq" << "\n";
        cout << area << "\n";
    }

    return 0;
}
```