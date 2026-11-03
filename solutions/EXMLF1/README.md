# [EXML Race (EXMLF1)](https://www.codechef.com/problems/EXMLF1)

- **Difficulty Rating**: 684
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ cars, each with a distance $d_i$ and a time $t_i$. The speed of each car is defined as $v_i = d_i / t_i$. We need to identify the car with the highest speed. If multiple cars share the same maximum speed, we must select the one with the smallest index (label).

## Intuition & Mathematical Observation
1. **Speed Calculation**: Since the problem asks for the maximum speed, we calculate $v_i = d_i / t_i$ for each car. Given the constraints ($d_i, t_i \le 100$), integer division is sufficient for comparison.
2. **Tie-Breaking**: The problem requires the smallest index in case of a tie. By iterating from $i = 1$ to $N$ and only updating our "best" car when we find a speed **strictly greater** than the current maximum, we naturally preserve the smallest index for any tied values encountered later.
3. **Efficiency**: With $N \le 100$ and $T \le 100$, a simple linear scan $O(N)$ per test case is highly efficient and well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of cars. Given the constraints, this performs at most $10^4$ operations, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only store a few variables to keep track of the current maximum speed and the best label found so far.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N cars with distance d_i and time t_i.
 * Speed v_i = d_i / t_i.
 * We need to find the car with the maximum speed.
 * If multiple cars have the same maximum speed, choose the one with the smallest label (index).
 */

void solve() {
    int N;
    cin >> N;
    
    int best_label = -1;
    int max_speed = -1;
    
    for (int i = 1; i <= N; ++i) {
        int d, t;
        cin >> d >> t;
        int current_speed = d / t;
        
        // If current car is strictly faster, update max_speed and best_label.
        // If speeds are equal, we do nothing, ensuring the smallest index is kept.
        if (current_speed > max_speed) {
            max_speed = current_speed;
            best_label = i;
        }
    }
    
    cout << best_label << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```