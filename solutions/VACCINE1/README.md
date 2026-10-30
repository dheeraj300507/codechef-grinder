# [Vaccine Production (VACCINE1)](https://www.codechef.com/problems/VACCINE1)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two companies, A and B, that produce vaccines. Company A starts production on day $D_1$ and produces $V_1$ vaccines per day. Company B starts production on day $D_2$ and produces $V_2$ vaccines per day. We need to determine the earliest day $d$ such that the cumulative number of vaccines produced by both companies reaches or exceeds a target value $P$.

## Intuition & Mathematical Observation
The production process is cumulative. On any given day $d$:
- If $d < D_1$, Company A contributes 0 vaccines.
- If $d \ge D_1$, Company A contributes $V_1$ vaccines.
- If $d < D_2$, Company B contributes 0 vaccines.
- If $d \ge D_2$, Company B contributes $V_2$ vaccines.

Since the constraints on $P$, $D$, and $V$ are small ($P \le 1000$, $D, V \le 100$), a **simulation approach** is highly efficient. We can simply increment the day counter starting from 1 and accumulate the production of both companies until the total reaches $P$. This avoids complex algebraic formulas involving conditional logic and is less prone to off-by-one errors.

## Complexity Analysis
- **Time Complexity**: $O(P / \min(V_1, V_2))$, which is effectively $O(P)$ in the worst case. Given $P \le 1000$, this performs well within the time limits.
- **Space Complexity**: $O(1)$, as we only store a few integer variables to track the state of production.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the smallest day 'd' such that the total vaccines produced
 * by Company A and Company B is >= P.
 * 
 * Company A starts on day D1 and produces V1 per day.
 * Company B starts on day D2 and produces V2 per day.
 * 
 * Since the constraints are very small (P <= 1000, D, V <= 100),
 * we can simply iterate day by day starting from 1 until the condition is met.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    long long total_vaccines = 0;
    int day = 0;

    // Simulate day by day
    while (total_vaccines < P) {
        day++;
        if (day >= D1) {
            total_vaccines += V1;
        }
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}
```