# [Dice Deception (DIDE)](https://www.codechef.com/problems/DIDE)

- **Difficulty Rating**: 1106
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ dice, each showing a value $A_i$ between 1 and 6. You are allowed to perform at most $K$ operations. In one operation, you can choose any die and flip it, changing its value from $x$ to $7 - x$. The goal is to maximize the total sum of the values on the $N$ dice after performing at most $K$ flips.

## Intuition & Mathematical Observation
To maximize the total sum, we need to determine which dice flips result in a net gain.
1.  **Gain Calculation**: Flipping a die with value $x$ changes the sum by $(7 - x) - x = 7 - 2x$.
2.  **Condition for Improvement**: A flip is beneficial if $7 - 2x > 0$, which simplifies to $x < 3.5$. This means only dice with values **1, 2, or 3** should be flipped.
    *   Flipping 1 gives a gain of $+5$ (becomes 6).
    *   Flipping 2 gives a gain of $+3$ (becomes 5).
    *   Flipping 3 gives a gain of $+1$ (becomes 4).
3.  **Strategy**: 
    *   Identify all dice where $A_i \in \{1, 2, 3\}$.
    *   To maximize the sum, we should prioritize the flips that provide the largest gain. Since the gain is $7-2x$, smaller values of $x$ yield larger gains.
    *   Sort the eligible dice in ascending order and perform up to $K$ flips.
    *   If $K$ is greater than the number of available dice with values 1, 2, or 3, we stop flipping, as flipping any remaining dice (values 4, 5, or 6) would result in a net loss.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case due to sorting the `to_flip` vector. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the input array and the list of dice eligible for flipping.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N dice with values A_i.
 * Flipping a die changes its value from x to (7 - x).
 * We can perform at most K flips.
 * To maximize the sum, we should prioritize flipping dice where (7 - A_i) > A_i.
 * This inequality simplifies to 7 > 2 * A_i, or A_i < 3.5.
 * Thus, we should flip dice with values 1, 2, or 3.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    long long current_sum = 0;
    vector<int> to_flip;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        current_sum += A[i];
        // A die is worth flipping if 7 - A[i] > A[i]
        // i.e., A[i] < 3.5, so A[i] is 1, 2, or 3.
        if (7 - A[i] > A[i]) {
            to_flip.push_back(A[i]);
        }
    }

    // Sort to flip the most beneficial ones first (smallest values give largest gain)
    sort(to_flip.begin(), to_flip.end());

    int flips_done = 0;
    for (int val : to_flip) {
        if (flips_done < K) {
            current_sum += (7 - val) - val;
            flips_done++;
        } else {
            break;
        }
    }

    cout << current_sum << "\n";
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