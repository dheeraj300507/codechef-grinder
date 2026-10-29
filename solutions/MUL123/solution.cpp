#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with N. We have two operations:
 * 1. N = N + 1
 * 2. N = next_multiple_of_5(N)
 * 
 * Since N is small (up to 100), we can use Breadth-First Search (BFS) 
 * to find the shortest path to a multiple of 3.
 * 
 * BFS state: current value of N.
 * Transitions:
 * - N -> N + 1
 * - N -> ((N / 5) + 1) * 5
 */

int solve() {
    int N;
    cin >> N;

    if (N % 3 == 0) return 0;

    // BFS setup
    // Since N <= 100, the state space is small. 
    // Even if N grows, it won't exceed a few hundred.
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    // Visited array to prevent infinite loops
    vector<bool> visited(1000, false);
    visited[N] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int val = curr.first;
        int dist = curr.second;

        // Try operation 1: N + 1
        int next1 = val + 1;
        if (next1 % 3 == 0) return dist + 1;
        if (next1 < 1000 && !visited[next1]) {
            visited[next1] = true;
            q.push({next1, dist + 1});
        }

        // Try operation 2: next multiple of 5
        int next2 = ((val / 5) + 1) * 5;
        if (next2 % 3 == 0) return dist + 1;
        if (next2 < 1000 && !visited[next2]) {
            visited[next2] = true;
            q.push({next2, dist + 1});
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