# [Chef and Interactive Contests (CHFINTRO)](https://www.codechef.com/problems/CHFINTRO)

- **Difficulty Rating**: 951
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ contestants, each with a specific rating $R$. We are also provided with a threshold rating $r$. The task is to determine, for each contestant, whether they are a "Good boi" or a "Bad boi" based on their rating. Specifically:
- If a contestant's rating $R$ is greater than or equal to the threshold $r$, they are classified as a **"Good boi"**.
- Otherwise, they are classified as a **"Bad boi"**.

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. Since we need to classify each contestant individually based on a constant threshold $r$, we can iterate through the list of $N$ ratings and apply a simple conditional check:
- If $R \ge r$, print "Good boi".
- Else, print "Bad boi".

No complex data structures or algorithms are required; a simple loop processing the input stream is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of contestants. We perform a constant time operation for each of the $N$ inputs.
- **Space Complexity**: $O(1)$, as we only store a few variables ($N, r, R$) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N contestants and a threshold rating r.
 * For each contestant with rating R:
 * - If R >= r, they are a "Good boi".
 * - If R < r, they are a "Bad boi".
 * 
 * Constraints:
 * N <= 1000
 * 1300 <= r, R <= 1501
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long r;
    
    // Read N (number of contestants) and r (threshold rating)
    if (!(cin >> N >> r)) return 0;

    // Process each contestant's rating
    for (int i = 0; i < N; ++i) {
        long long R;
        cin >> R;
        
        // Check condition and print result
        if (R >= r) {
            cout << "Good boi" << "\n";
        } else {
            cout << "Bad boi" << "\n";
        }
    }

    return 0;
}
```