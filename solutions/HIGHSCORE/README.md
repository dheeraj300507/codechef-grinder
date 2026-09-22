# [Score High (HIGHSCORE)](https://www.codechef.com/problems/HIGHSCORE)

- **Difficulty Rating**: 672
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is taking a test consisting of $N$ questions. He is given the total count of answers for each option (A, B, C, and D) in the answer key. Chef wants to maximize his guaranteed score. He can choose to mark all $N$ questions with the same option. We need to determine the maximum number of marks he can guarantee by choosing the optimal option.

## Intuition & Mathematical Observation
The problem asks us to maximize the number of correct answers Chef can guarantee. 
- If Chef chooses to mark all $N$ questions with option 'A', he will get exactly $N_A$ marks, where $N_A$ is the number of questions whose correct answer is 'A'.
- Similarly, if he chooses 'B', 'C', or 'D', he will get $N_B$, $N_C$, or $N_D$ marks respectively.

Since Chef wants to maximize his guaranteed marks, he should simply pick the option that appears most frequently in the answer key. Mathematically, the answer is:
$$\text{Result} = \max(N_A, N_B, N_C, N_D)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing a constant number of comparisons to find the maximum of four integers.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef knows the total count of answers for each option (A, B, C, D).
 * He wants to maximize the marks he can guarantee.
 * 
 * If Chef decides to mark all N problems with a specific option (e.g., option A),
 * he is guaranteed to get exactly N_A marks, because there are exactly N_A 
 * problems where the answer is A.
 * 
 * Since he wants to maximize his guaranteed marks, he should choose the option 
 * that appears the most frequently in the answer key.
 * 
 * Therefore, the answer is simply max(N_A, N_B, N_C, N_D).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        long long na, nb, nc, nd;
        cin >> na >> nb >> nc >> nd;

        // The maximum marks Chef can guarantee is the maximum of the counts
        // of the four options.
        long long max_marks = max({na, nb, nc, nd});
        
        cout << max_marks << "\n";
    }

    return 0;
}
```