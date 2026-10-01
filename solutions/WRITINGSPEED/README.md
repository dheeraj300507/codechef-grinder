# [Writing Speed (WRITINGSPEED)](https://www.codechef.com/problems/WRITINGSPEED)

- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary
Rahul needs to write 5 pages. He has a total of 60 minutes available. Given that he takes $X$ minutes to write a single page, determine if he can complete all 5 pages within the 60-minute limit.

## Intuition & Mathematical Observation
To solve this problem, we need to calculate the total time required to write 5 pages and compare it against the available time.

1.  **Calculate Total Time**: Since Rahul writes 5 pages and each page takes $X$ minutes, the total time spent is $5 \times X$.
2.  **Check Condition**: The problem states he has 60 minutes. Therefore, he can complete the task if:
    $$5 \times X \le 60$$
3.  **Simplify**: Dividing both sides by 5, we get:
    $$X \le 12$$
    If $X$ is 12 or less, the output should be `YES`; otherwise, it should be `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as it involves a simple arithmetic comparison.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Rahul has 5 pages to write.
 * He has a total of 60 minutes.
 * He takes X minutes per page.
 * Total time taken = 5 * X.
 * Condition: 5 * X <= 60.
 * Simplifying: X <= 12.
 * 
 * Constraints: 1 <= X <= 1000.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the input X
    if (cin >> X) {
        // Check if total time (5 * X) is within the 60-minute limit
        if (5 * X <= 60) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```