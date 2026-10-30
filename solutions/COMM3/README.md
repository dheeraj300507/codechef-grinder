# [Three Way Communications (COMM3)](https://www.codechef.com/problems/COMM3)

- **Difficulty Rating**: 1083
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the coordinates of three locations: the Chef, the Head Server, and the Sous-chef. We are also given a maximum communication range $R$. Two locations can communicate if the Euclidean distance between them is at most $R$. We need to determine if all three locations can communicate with each other, either directly or indirectly (i.e., the graph formed by these three points must be connected).

## Intuition & Mathematical Observation
1. **Distance Calculation**: The Euclidean distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ is $\sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}$. To avoid floating-point precision issues and the computational cost of square roots, we compare the squared distance $(x_1-x_2)^2 + (y_1-y_2)^2$ with $R^2$.
2. **Connectivity Logic**: With only three points (let's call them $P_0, P_1, P_2$), the graph is connected if there is a path between any two nodes. 
   - There are three possible communication links: $(P_0, P_1)$, $(P_0, P_2)$, and $(P_1, P_2)$.
   - For three nodes to be connected, we need at least two of these links to exist. If two links exist, all three nodes are connected (e.g., if $P_0-P_1$ and $P_1-P_2$ exist, then $P_0$ can reach $P_2$ via $P_1$).
   - If fewer than two links exist, the graph is disconnected.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of arithmetic operations (3 distance calculations and 3 comparisons) regardless of the input values.
- **Space Complexity**: $O(1)$. We only store the coordinates of the three points and the squared distances, which requires a constant amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three points (Chef, Head Server, Sous-chef).
 * Let the points be P1, P2, P3.
 * Two points can communicate if the Euclidean distance between them is <= R.
 * This is equivalent to distance squared <= R^2.
 * 
 * We need to check if the graph formed by these 3 nodes is connected.
 * Since there are only 3 nodes, the graph is connected if at least 2 of the 
 * 3 possible edges exist.
 */

typedef long long ll;

// Function to calculate squared Euclidean distance
ll distSq(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    ll R;
    cin >> R;
    ll R2 = R * R;
    
    ll x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Calculate squared distances between all pairs
    ll d01 = distSq(x[0], y[0], x[1], y[1]);
    ll d02 = distSq(x[0], y[0], x[2], y[2]);
    ll d12 = distSq(x[1], y[1], x[2], y[2]);
    
    // Check connectivity
    // Count how many edges are valid (distance <= R)
    int count = 0;
    if (d01 <= R2) count++;
    if (d02 <= R2) count++;
    if (d12 <= R2) count++;
    
    // For 3 nodes to be connected, we need at least 2 edges.
    if (count >= 2) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
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