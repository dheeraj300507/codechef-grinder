# [Ticket Fine (TCKTFINE)](https://www.codechef.com/problems/TCKTFINE)

- **Difficulty Rating**: 373
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the total fine collected by a ticket collector. We are given:
- $X$: The fine amount per passenger who does not have a ticket.
- $P$: The total number of passengers on the train.
- $Q$: The number of passengers who have a valid ticket.

We need to determine the total fine collected from the passengers who do not have a ticket.

## Intuition & Mathematical Observation
1. **Identify the number of ticketless passengers**: Since there are $P$ total passengers and $Q$ of them have tickets, the number of passengers without tickets is simply $P - Q$.
2. **Calculate the total fine**: Each of these $(P - Q)$ passengers must pay a fine of $X$. Therefore, the total fine is the product of the number of ticketless passengers and the fine amount:
   $$\text{Total Fine} = (P - Q) \times X$$
3. **Constraints**: Given the nature of the problem, $P$ is always greater than or equal to $Q$, ensuring the result is non-negative. Using `long long` is a safe practice to prevent potential overflow, although standard `int` would suffice for the given constraints.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant number of arithmetic operations for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - X: Fine per passenger without a ticket.
 * - P: Total number of passengers.
 * - Q: Total number of tickets.
 * - Passengers without tickets = P - Q.
 * - Total fine = (P - Q) * X.
 * 
 * Complexity:
 * - Time: O(T), where T is the number of test cases.
 * - Space: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, p, q;
        if (!(cin >> x >> p >> q)) break;
        
        // Calculate number of passengers without tickets
        long long passengers_without_tickets = p - q;
        
        // Calculate total fine
        long long total_fine = passengers_without_tickets * x;
        
        // Output the result
        cout << total_fine << "\n";
    }

    return 0;
}
```