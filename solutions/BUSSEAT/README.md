# [Bus Seating (BUSSEAT)](https://www.codechef.com/problems/BUSSEAT)

- **Difficulty Rating**: 640
- **Solved in**: 1 attempt(s)

## Problem Summary
There is a bus with $N$ rows, where each row has 2 seats. Passengers board the bus one by one. The seating strategy is as follows:
1. Passengers prefer to sit in an empty row first.
2. If no empty row is available, they sit in a row that already has one passenger.

We need to calculate the total number of people who end up sitting next to someone.

## Intuition & Mathematical Observation
*   **Total Rows**: $N$
*   **Total Seats**: $2N$
*   **Case 1: $K \le N$**
    If the number of passengers $K$ is less than or equal to the number of rows $N$, every passenger will choose an empty row. Since each passenger occupies their own row, no one will have a neighbor.
    *   **Result**: $0$
*   **Case 2: $K > N$**
    *   The first $N$ passengers will each occupy one row (one seat per row).
    *   Once $N$ passengers are seated, all $N$ rows are occupied by exactly one person.
    *   The remaining $(K - N)$ passengers must now sit in a row that already has one person.
    *   When a new passenger sits in a row that already has one person, both the original occupant and the new passenger now have a neighbor.
    *   Therefore, for each of the $(K - N)$ new passengers, 2 people end up "sitting next to someone."
    *   **Result**: $2 \times (K - N)$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ constant time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * People enter one by one.
 * Strategy:
 * 1. People prefer to sit in an empty row.
 * 2. If no empty row is available, they sit next to someone.
 * 
 * Let N be the number of rows.
 * If K <= N:
 * Each person takes one row. No one sits next to anyone. Result = 0.
 * 
 * If K > N:
 * The first N people will each take one row (one seat per row).
 * After N people, all N rows are occupied by 1 person each.
 * The remaining (K - N) people must sit in a row that already has 1 person.
 * When a person sits in a row that already has 1 person, both the person 
 * already there and the new person are now "sitting next to somebody".
 * 
 * Total = 2 * (K - N).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            cout << 0 << "\n";
        } else {
            // The number of people who end up sitting next to someone is 2 * (K - N)
            cout << 2 * (k - n) << "\n";
        }
    }

    return 0;
}
```