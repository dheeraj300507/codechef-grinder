#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X and Y. We want to reach a state where X >= 2Y or Y >= 2X.
 * In one operation, we can increment or decrement X or Y by 1.
 * Since the constraints are very small (X, Y <= 10), we can use a Breadth-First Search (BFS)
 * or simply iterate through all possible reachable states within a reasonable range.
 * Given the constraints, the number of operations will be small.
 * 
 * Let's define the state as (x, y). We want to reach any state where x >= 2y or y >= 2x.
 * Since we want the minimum operations, BFS is the standard approach for shortest path in a state space.
 */

struct State {
    int x, y, dist;
};

int solve() {
    int X, Y;
    cin >> X >> Y;

    // If already satisfied
    if (X >= 2 * Y || Y >= 2 * X) return 0;

    // BFS to find the minimum operations
    // Since X, Y are small (up to 10), the target state will be close.
    // A range of [0, 30] for x and y is more than sufficient.
    queue<pair<int, int>> q;
    map<pair<int, int>, int> dist;

    q.push({X, Y});
    dist[{X, Y}] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int cx = curr.first;
        int cy = curr.second;
        int d = dist[{cx, cy}];

        if (cx >= 2 * cy || cy >= 2 * cx) return d;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // Constraints: X, Y are positive integers.
            // We keep them within a reasonable bound to avoid infinite search.
            if (nx >= 1 && ny >= 1 && nx <= 30 && ny <= 30) {
                if (dist.find({nx, ny}) == dist.end()) {
                    dist[{nx, ny}] = d + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}