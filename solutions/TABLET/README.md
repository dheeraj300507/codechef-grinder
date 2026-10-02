# [Buying New Tablet (TABLET)](https://www.codechef.com/problems/TABLET)

- **Difficulty Rating**: 1037
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a budget $B$ and a list of $N$ tablets, each defined by its width $W$, height $H$, and price $P$. The goal is to find the tablet with the largest screen area ($W \times H$) that you can afford (i.e., $P \le B$). If no tablet fits within the budget, you must output "no tablet".

## Intuition & Mathematical Observation
The problem is a straightforward search problem. Since we want to maximize the area, we can iterate through the list of tablets and maintain a variable `max_area` to store the largest area found so far among the tablets that satisfy the condition $P \le B$.

1. Initialize `max_area` to -1 and a boolean flag `found` to `false`.
2. For each tablet:
   - Check if the price $P$ is less than or equal to the budget $B$.
   - If it is, calculate the area as $W \times H$.
   - Compare this area with `max_area`. If it is larger, update `max_area` and set `found` to `true`.
3. After checking all tablets, if `found` is still `false`, print "no tablet". Otherwise, print the `max_area`.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of tablets per test case. We perform a single pass through the list of tablets for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current tablet's dimensions and the maximum area found, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Buying New Tablet
 * Approach:
 * For each test case, iterate through all N tablets.
 * Check if the price P_i is less than or equal to the budget B.
 * If it is, calculate the area (W_i * H_i) and keep track of the maximum area found so far.
 * If no tablet is affordable, output "no tablet".
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1)
 */

void solve() {
    int N;
    long long B;
    cin >> N >> B;

    long long max_area = -1;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        long long W, H, P;
        cin >> W >> H >> P;

        if (P <= B) {
            long long current_area = W * H;
            if (current_area > max_area) {
                max_area = current_area;
            }
            found = true;
        }
    }

    if (!found) {
        cout << "no tablet" << "\n";
    } else {
        cout << max_area << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```