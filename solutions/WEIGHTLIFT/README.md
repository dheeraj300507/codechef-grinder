# [Weightlifting (WEIGHTLIFT)](https://www.codechef.com/problems/WEIGHTLIFT)

- **Difficulty Rating**: 270
- **Solved in**: 1 attempt(s)

## Problem Summary
In a weightlifting competition, an athlete performs three rounds. In each round, the athlete is given two attempts to lift the maximum possible weight. The final score for each round is determined by the maximum weight lifted between the two attempts. The goal is to calculate the total score, which is the sum of the maximum weights from all three rounds.

## Intuition & Mathematical Observation
The problem asks us to process three pairs of integers. For each pair $(x_i, y_i)$, we need to select the larger value, as that represents the best performance for that specific round. 

Let the attempts for the three rounds be $(a_1, a_2)$, $(b_1, b_2)$, and $(c_1, c_2)$.
The total score $S$ is calculated as:
$$S = \max(a_1, a_2) + \max(b_1, b_2) + \max(c_1, c_2)$$

Since we are only dealing with three pairs, we can simply read the six inputs, compute the maximum for each pair using the built-in `max()` function, and sum them up.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons and additions regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed number of variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: WEIGHTLIFT
 * The goal is to find the maximum of two attempts for each of the three rounds
 * and sum these maximums to get the total score.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a1, a2, b1, b2, c1, c2;
    
    // Reading the 6 space-separated integers
    if (cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2) {
        // Calculate the best score for each round
        long long round1 = max(a1, a2);
        long long round2 = max(b1, b2);
        long long round3 = max(c1, c2);
        
        // Calculate total score
        long long total_score = round1 + round2 + round3;
        
        // Output the result
        cout << total_score << "\n";
    }

    return 0;
}
```