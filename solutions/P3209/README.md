# [Small GCD Sort (P3209)](https://www.codechef.com/problems/P3209)

- **Difficulty Rating**: 1039
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we have $N$ players indexed from $1$ to $N$. Each player $i$ is assigned a score equal to $\gcd(i, N)$. The task is to sort these players based on two criteria:
1. **Primary**: Players with a higher score come first.
2. **Secondary**: If two players have the same score, the player with the smaller index comes first.

## Intuition & Mathematical Observation
Since the constraint for $N$ is small (up to 100), we can directly compute the score for every player from $1$ to $N$ using the Euclidean algorithm for GCD. 

To implement the sorting logic:
- We store each player as a pair (or struct) containing their `id` and their calculated `score`.
- We define a custom comparator function:
    - If `score_a != score_b`, return `score_a > score_b` (descending order of scores).
    - If `score_a == score_b`, return `id_a < id_b` (ascending order of indices).
- After sorting the collection, we simply print the `id` of each player in the new order.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log(\min(i, N)))$, where $T$ is the number of test cases. Calculating the GCD takes logarithmic time, and sorting $N$ elements takes $O(N \log N)$. Given $N \le 100$, this is well within the time limits.
- **Space Complexity**: $O(N)$ to store the list of players.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N players, each with a score gcd(i, N).
 * Sorting criteria:
 * 1. Higher score comes first.
 * 2. If scores are equal, smaller player index comes first.
 */

struct Player {
    int id;
    int score;
};

// Custom comparator to handle the sorting criteria
bool comparePlayers(const Player& a, const Player& b) {
    if (a.score != b.score) {
        return a.score > b.score; // Higher score first
    }
    return a.id < b.id; // Smaller index first
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int N;
    cin >> N;
    vector<Player> players(N);
    for (int i = 1; i <= N; ++i) {
        players[i - 1] = {i, gcd(i, N)};
    }
    
    // Sort using the custom comparator
    sort(players.begin(), players.end(), comparePlayers);
    
    // Output the sorted IDs
    for (int i = 0; i < N; ++i) {
        cout << players[i].id << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```