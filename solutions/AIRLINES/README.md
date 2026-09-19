# [Codechef Airlines (AIRLINES)](https://www.codechef.com/problems/AIRLINES)

- **Difficulty Rating**: 475
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef owns 10 airplanes, each with a seating capacity of $X$. There are $Y$ people who want to book a seat, and each seat costs $Z$. We need to calculate the maximum total earnings Chef can make, considering that he cannot sell more seats than the total capacity of his 10 airplanes.

## Intuition & Mathematical Observation
1. **Total Capacity**: Since there are 10 airplanes and each holds $X$ passengers, the total capacity is $10 \times X$.
2. **Seats Sold**: Chef can only sell seats to the number of people who want to book ($Y$), provided that $Y$ does not exceed the total capacity. Therefore, the number of seats sold is the minimum of the total capacity and the number of people: $\min(10 \times X, Y)$.
3. **Earnings**: The total earnings are simply the number of seats sold multiplied by the price per seat ($Z$).
4. **Data Types**: While the constraints ($X, Y, Z \le 100$) are small enough for standard integers, using `long long` is a good habit to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 10 airplanes.
 * Each airplane has a capacity of X.
 * Total capacity = 10 * X.
 * Number of people willing to book = Y.
 * Number of seats actually sold = min(Total capacity, Y).
 * Price per seat = Z.
 * Total earnings = min(10 * X, Y) * Z.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Total capacity of all 10 airplanes
        long long total_capacity = 10 * x;
        
        // Number of people who can actually book a seat
        long long seats_sold = min(total_capacity, y);
        
        // Total earnings
        long long earnings = seats_sold * z;
        
        cout << earnings << "\n";
    }
    
    return 0;
}
```