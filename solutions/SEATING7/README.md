# [Seating (SEATING7)](https://www.codechef.com/problems/SEATING7)

- **Difficulty Rating**: 913
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given a row of $N$ seats, some of which are already occupied. We need to seat $K$ additional people. For each of the $K$ people, they will always choose the **smallest available seat index** (the leftmost empty seat). We need to output the seat numbers assigned to these $K$ people in the order they are seated.

## Intuition & Mathematical Observation
Since $N, M,$ and $K$ are small (up to 100), a direct simulation is the most efficient approach. 
1. We maintain a boolean array `occupied` of size $N+1$ to track the status of each seat.
2. We mark the initially occupied seats as `true`.
3. For each of the $K$ people, we iterate through the seats from $1$ to $N$. The first index `i` where `occupied[i]` is `false` is the seat the person takes.
4. Once a seat is taken, we mark it as `true` so that subsequent people do not choose it.
5. Using `ios_base::sync_with_stdio(false); cin.tie(NULL);` ensures that the I/O operations are fast enough to handle the test cases within the time limit.

## Complexity Analysis
- **Time Complexity**: $O(T \times K \times N)$, where $T$ is the number of test cases. Given $T, N, K \le 100$, the total operations are roughly $10^6$, which comfortably fits within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the status of the seats in the `occupied` vector.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * N <= 100, M, K <= N.
 * The simulation approach is O(T * K * N).
 * With T=100, N=100, K=100, total operations ~ 1,000,000.
 * This is well within the time limit.
 */

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<bool> occupied(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int seat;
        cin >> seat;
        if (seat >= 1 && seat <= N) {
            occupied[seat] = true;
        }
    }

    bool first = true;
    for (int k = 0; k < K; ++k) {
        for (int seat = 1; seat <= N; ++seat) {
            if (!occupied[seat]) {
                occupied[seat] = true;
                if (!first) cout << " ";
                cout << seat;
                first = false;
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
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