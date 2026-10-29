#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at city X and jumps by K each day in a circular arrangement of N cities.
 * The sequence of cities visited is: X, (X+K)%N, (X+2K)%N, (X+3K)%N, ...
 * This is a classic problem of finding if Y exists in the sequence (X + i*K) % N.
 * This is equivalent to checking if there exists an integer i >= 0 such that:
 * (X + i*K) % N == Y
 * Which is equivalent to:
 * (i * K) % N == (Y - X + N) % N
 * 
 * Since N is small (up to 1000), we can simply simulate the process.
 * The virus will visit at most N distinct cities before repeating the cycle.
 * If we visit a city we have already visited, we stop.
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