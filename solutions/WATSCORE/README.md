# [That Is My Score! (WATSCORE)](https://www.codechef.com/problems/WATSCORE)

- **Difficulty Rating**: 1094
- **Solved in**: 1 attempt(s)

## Problem Summary
In a programming contest, there are 11 problems in total, but only problems 1 through 8 are considered for the final score. A participant can make multiple submissions for the same problem. The final score for a participant is the sum of the maximum scores obtained for each of the problems from 1 to 8. Given a list of submissions (problem number and score), calculate the total score.

## Intuition & Mathematical Observation
The core of the problem is to track the "best" score for each specific problem index (1 through 8). Since we only care about the maximum score per problem, we can maintain an array of size 9 (to accommodate 1-based indexing) initialized to zero. 

1. **Filtering**: Submissions for problems 9, 10, and 11 do not contribute to the total score, so they should be ignored.
2. **Updating**: For every submission $(p, s)$, if $p \leq 8$, we update the stored maximum for problem $p$ if the new score $s$ is greater than the current stored value.
3. **Aggregation**: After processing all submissions, the total score is simply the sum of the values stored in our array for indices 1 through 8.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of submissions. We iterate through the submissions exactly once and then perform a constant-time summation of 8 elements.
- **Space Complexity**: $O(1)$, as we use a fixed-size array of size 9 regardless of the number of submissions.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 11 problems, but only problems 1 through 8 are scorable.
 * For each scorable problem, we need to find the maximum score achieved.
 * The total score is the sum of these maximums.
 * 
 * Approach:
 * 1. Use an array of size 9 (indices 1-8) to store the maximum score for each scorable problem.
 * 2. Initialize the array with 0.
 * 3. For each submission (p, s):
 *    - If p <= 8, update max_scores[p] = max(max_scores[p], s).
 * 4. Sum the values in the array from index 1 to 8.
 */

void solve() {
    int n;
    cin >> n;
    
    // max_scores[i] stores the best score for problem i (1-8)
    vector<int> max_scores(9, 0);
    
    for (int i = 0; i < n; ++i) {
        int p, s;
        cin >> p >> s;
        // Only consider problems 1 through 8
        if (p >= 1 && p <= 8) {
            if (s > max_scores[p]) {
                max_scores[p] = s;
            }
        }
    }
    
    long long total_score = 0;
    for (int i = 1; i <= 8; ++i) {
        total_score += max_scores[i];
    }
    
    cout << total_score << "\n";
}

int main() {
    // Fast I/O
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