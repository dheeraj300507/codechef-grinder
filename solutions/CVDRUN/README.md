# [Covid Run (CVDRUN)](https://www.codechef.com/problems/CVDRUN)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ cities arranged in a circle, labeled from $0$ to $N-1$. A virus starts at city $X$ and jumps to city $(X + K) \pmod N$ every day. We need to determine if the virus will ever reach city $Y$ given the parameters $N, K, X,$ and $Y$.

## Intuition & Mathematical Observation
The sequence of cities visited by the virus follows the pattern: $X, (X+K) \pmod N, (X+2K) \pmod N, \dots$. 

Since there are only $N$ cities, the sequence must eventually repeat. Specifically, the virus will visit at most $N$ distinct cities before returning to the starting city $X$. Therefore, we can simulate the process by jumping $K$ steps at a time. If we encounter city $Y$ during the simulation, the answer is "YES". If we encounter a city that has already been visited (indicating we have completed a full cycle) without having reached $Y$, the answer is "NO".

Alternatively, this can be viewed as a modular arithmetic problem: we are looking for a non-negative integer $i$ such that $(X + i \cdot K) \equiv Y \pmod N$. This is equivalent to solving $i \cdot K \equiv (Y - X) \pmod N$ for $i$. Given the constraints ($N \le 1000$), a simple simulation is efficient and easy to implement.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. In the worst case, we visit all $N$ cities once before determining if $Y$ is reachable.
- **Space Complexity**: $O(N)$ to store the `visited` array, which keeps track of the cities the virus has already infected to detect cycles.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at city X and jumps by K each day in a circular arrangement of N cities.
 * The sequence of cities visited is: X, (X+K)%N, (X+2K)%N, (X+3K)%N, ...
 * This is a classic problem of finding if Y exists in the sequence (X + i*K) % N.
 * 
 * Since N is small (up to 1000), we can simply simulate the process.
 * The virus will visit at most N distinct cities before repeating the cycle.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // visited array to keep track of infected cities
    vector<bool> visited(N, false);
    
    int current = X;
    bool found = false;
    
    // Simulate the jumps
    // We can jump at most N times. If we haven't reached Y by then,
    // we will never reach it because we would have entered a cycle.
    for (int i = 0; i < N; ++i) {
        if (current == Y) {
            found = true;
            break;
        }
        
        // If we hit a city already visited, we are in a loop and Y is not reachable
        if (visited[current]) {
            break;
        }
        
        visited[current] = true;
        current = (current + K) % N;
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```