# [Coldplay Tickets (COLDPLAYTICK)](https://www.codechef.com/problems/COLDPLAYTICK)

- **Difficulty Rating**: 292
- **Solved in**: 1 attempt(s)

## Problem Summary
You are planning to buy tickets for a Coldplay concert. You need to buy one ticket for yourself and one ticket for each of your $N$ friends. Given that each ticket costs 5000 units, calculate the total cost for all the tickets.

## Intuition & Mathematical Observation
The problem asks for the total cost of tickets for a group. 
- You are buying a ticket for yourself (1 person).
- You are buying tickets for your $N$ friends.
- Therefore, the total number of people is $N + 1$.
- Since each ticket costs 5000, the total cost is calculated as:
  $$\text{Total Cost} = (N + 1) \times 5000$$

Given the constraints ($1 \le N \le 5$), the result will easily fit within a standard integer type, though using `long long` is a safe practice in competitive programming to prevent overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves a simple arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Coldplay Tickets
 * Logic: You are buying tickets for yourself and N friends.
 * Total people = N + 1.
 * Cost per ticket = 5000.
 * Total cost = (N + 1) * 5000.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the number of friends N
    if (cin >> n) {
        // Calculate total people and multiply by ticket cost
        long long total_people = (long long)n + 1;
        long long total_cost = total_people * 5000;
        
        // Output the result
        cout << total_cost << "\n";
    }

    return 0;
}
```