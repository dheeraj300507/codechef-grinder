# [Movie Weekend (MOVIEWKN)](https://www.codechef.com/problems/MOVIEWKN)

- **Difficulty Rating**: 1175
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given two arrays, $L$ and $R$, representing the length and rating of $n$ movies, respectively. You need to select a movie to watch based on the following priority rules:
1. Choose the movie with the **maximum product** of $L[i] \times R[i]$.
2. If there is a tie in the product, choose the movie with the **maximum rating** ($R[i]$).
3. If there is still a tie, choose the movie with the **smallest index** (1-based).

## Intuition & Mathematical Observation
The problem asks us to find the "best" movie by comparing them based on a specific hierarchy of criteria. Since the number of movies $n$ is small (up to 100), a linear scan is sufficient.

- We maintain variables to store the `max_prod`, `max_rating`, and `best_idx` found so far.
- As we iterate through the movies from $i = 0$ to $n-1$:
    - We calculate the current product $P = L[i] \times R[i]$.
    - If $P$ is strictly greater than our current `max_prod`, we update our best movie.
    - If $P$ is equal to `max_prod`, we check if the current rating $R[i]$ is strictly greater than our current `max_rating`. If so, we update.
    - If both $P$ and $R[i]$ are equal to our current bests, we do nothing. Because we iterate from index $0$ upwards, the first movie we encountered that satisfied the conditions is automatically the one with the smallest index.

## Complexity Analysis
- **Time Complexity**: $O(n)$ per test case, where $n$ is the number of movies. We perform a single pass through the arrays.
- **Space Complexity**: $O(n)$ to store the input arrays $L$ and $R$. (Note: This could be optimized to $O(1)$ by processing inputs on the fly, but $O(n)$ is well within limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: MOVIEWKN
 * Approach:
 * We need to select a movie based on three criteria in order of priority:
 * 1. Maximal product of L[i] * R[i].
 * 2. If products are equal, maximal R[i].
 * 3. If products and ratings are equal, minimal index (1-based).
 * 
 * Since n is small (up to 100), we can iterate through all movies and keep track 
 * of the best movie found so far based on these criteria.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> L(n), R(n);
    for (int i = 0; i < n; ++i) cin >> L[i];
    for (int i = 0; i < n; ++i) cin >> R[i];

    int best_idx = 0; // 0-based index of the best movie
    long long max_prod = -1;
    long long max_rating = -1;

    for (int i = 0; i < n; ++i) {
        long long current_prod = L[i] * R[i];
        
        if (current_prod > max_prod) {
            max_prod = current_prod;
            max_rating = R[i];
            best_idx = i;
        } else if (current_prod == max_prod) {
            if (R[i] > max_rating) {
                max_rating = R[i];
                best_idx = i;
            } else if (R[i] == max_rating) {
                // If ratings are equal, we prefer the smaller index.
                // Since we iterate from 0 to n-1, the first one we encounter
                // is already the smallest index. No action needed.
                continue;
            }
        }
    }

    // Output 1-based index
    cout << best_idx + 1 << "\n";
}

int main() {
    // Fast I/O
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