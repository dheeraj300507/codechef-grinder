# [Chef Eren (CHEFEREN)](https://www.codechef.com/problems/CHEFEREN)

- **Difficulty Rating**: 706
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef has a series of $N$ episodes. Episodes with even indices (2, 4, 6, ...) have a duration of $A$ minutes, while episodes with odd indices (1, 3, 5, ...) have a duration of $B$ minutes. The goal is to calculate the total duration of all $N$ episodes combined.

## Intuition & Mathematical Observation
To solve this efficiently without iterating through every episode, we can use simple arithmetic:

1. **Counting Even Indices**: In a range from $1$ to $N$, the number of even integers is given by $\lfloor N / 2 \rfloor$.
2. **Counting Odd Indices**: Since there are $N$ total episodes, the number of odd integers is simply the total count minus the even count: $N - \lfloor N / 2 \rfloor$.
3. **Calculation**: The total duration is the sum of the products of the counts and their respective durations:
   $$\text{Total Duration} = (\text{even\_count} \times A) + (\text{odd\_count} \times B)$$

This approach allows us to compute the answer in constant time per test case.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * N episodes, 1 to N.
 * Even indexed: 2, 4, 6... have duration A.
 * Odd indexed: 1, 3, 5... have duration B.
 * 
 * Number of even indices in [1, N] is N / 2.
 * Number of odd indices in [1, N] is N - (N / 2).
 * 
 * Total duration = (even_count * A) + (odd_count * B).
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;

    int even_count = N / 2;
    int odd_count = N - even_count;

    int total_duration = (even_count * A) + (odd_count * B);
    cout << total_duration << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```