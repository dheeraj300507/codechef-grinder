# [Little Elephant and Candies (LECANDY)](https://www.codechef.com/problems/LECANDY)

- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ elephants and a total of $C$ candies. Each elephant $i$ requires a specific number of candies $A_i$ to be happy. We need to determine if it is possible to satisfy all $N$ elephants given the total supply of $C$ candies.

## Intuition & Mathematical Observation
To make every elephant happy, the total number of candies required is the sum of the individual requirements for each elephant:
$$\text{Total Needed} = \sum_{i=1}^{N} A_i$$

Since each elephant must receive at least their required amount, the condition for success is simply:
$$\text{Total Needed} \le C$$

If the total number of candies available ($C$) is greater than or equal to the sum of all $A_i$, we output "Yes". Otherwise, we output "No". Because the constraints allow $C$ to be up to $10^9$, we use a `long long` data type to prevent potential overflow during summation, although the sum of $A_i$ in this specific problem is relatively small ($100 \times 10,000 = 1,000,000$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elephants. We iterate through the list of requirements exactly once to calculate the sum. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only store the running sum and the current input value, requiring constant extra space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N elephants and C candies.
 * Each elephant K needs at least A_K candies.
 * To make all elephants happy, we need a total of at least sum(A_1, A_2, ..., A_N) candies.
 * If C >= sum(A_i), then it is possible to make them all happy.
 * Otherwise, it is impossible.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        
        long long total_needed = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            total_needed += a;
        }
        
        if (c >= total_needed) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```