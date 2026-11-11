# [Assignment Score (ASSIGNSCORE)](https://www.codechef.com/problems/ASSIGNSCORE)

- **Difficulty Rating**: 794
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has completed $N$ assignments and needs to complete one final assignment (the $(N+1)$-th) to pass the course. To pass, the average score across all $N+1$ assignments must be at least 50%. Each assignment is graded out of 100 marks. We need to determine the minimum score required on the final assignment to pass, or output -1 if it is impossible to achieve the required average.

## Intuition & Mathematical Observation
1. **Total Assignments**: There are $N+1$ assignments in total.
2. **Required Total Marks**: Since each assignment is worth 100 marks, the total possible marks are $100 \times (N+1)$. To get 50%, Chef needs at least:
   $$\text{Required Total} = 0.50 \times 100 \times (N+1) = 50 \times (N+1)$$
3. **Calculating the Score ($X$)**: Let $S$ be the sum of the scores of the first $N$ assignments. Let $X$ be the score of the $(N+1)$-th assignment. We need:
   $$S + X \geq 50 \times (N+1)$$
   $$X \geq 50 \times (N+1) - S$$
4. **Constraints on $X$**:
   - If the calculated $X > 100$, it is impossible to achieve the target, so we output `-1`.
   - If the calculated $X < 0$, it means Chef has already secured enough marks to pass regardless of the final score, so the minimum score required is `0`.
   - Otherwise, the answer is simply the calculated $X$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ assignments once to calculate their sum. Given the constraints, this is highly efficient.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N assignments already completed with scores A_1, ..., A_N.
 * There is one more assignment (the (N+1)-th).
 * Total assignments = N + 1.
 * Total possible marks = (N + 1) * 100.
 * To pass, Chef needs at least 50% of the total possible marks.
 * Required total marks = 0.5 * (N + 1) * 100 = 50 * (N + 1).
 * Let S be the sum of the first N assignments.
 * Let X be the score on the (N+1)-th assignment.
 * We need: S + X >= 50 * (N + 1)
 * Therefore: X >= 50 * (N + 1) - S
 */

void solve() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
    }

    long long target = 50LL * (N + 1);
    long long needed = target - sum;

    // If the required score is greater than 100, it's impossible.
    if (needed > 100) {
        cout << -1 << "\n";
    } 
    // If the required score is negative, he already has enough marks.
    else if (needed < 0) {
        cout << 0 << "\n";
    } 
    // Otherwise, output the calculated needed score.
    else {
        cout << needed << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```