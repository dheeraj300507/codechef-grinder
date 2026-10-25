# [Equal Difference (EQSUM)](https://www.codechef.com/problems/EQSUM)

- **Difficulty Rating**: 979
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we need to find the number of pairs $(i, j)$ such that $1 \le i < j \le N$ and the condition $A_i - A_j = i - j$ holds.

## Intuition & Mathematical Observation
The given condition is $A_i - A_j = i - j$. By rearranging the terms to group indices and values together, we get:
$$A_i - i = A_j - j$$

Let $B_k = A_k - k$ for all $1 \le k \le N$. The problem reduces to finding the number of pairs $(i, j)$ such that $i < j$ and $B_i = B_j$. 

This is a classic frequency counting problem. If a specific value $x$ appears $f$ times in the transformed array $B$, the number of ways to choose two distinct indices $i$ and $j$ such that $B_i = B_j = x$ is given by the combination formula $\binom{f}{2}$, which is:
$$\frac{f \times (f - 1)}{2}$$

By calculating the frequency of every unique value in $B$ and summing these combinations, we obtain the total count of valid pairs.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case due to the use of a `std::map` to store frequencies. Given the constraint $\sum N \le 2 \times 10^5$, this approach comfortably passes within the time limit.
- **Space Complexity**: $O(N)$ to store the frequencies of the transformed values in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition A_i - A_j = i - j is equivalent to A_i - i = A_j - j.
 * We transform the array into B where B_k = A_k - k.
 * We then count the frequency of each value in B and calculate 
 * the number of pairs using (count * (count - 1)) / 2.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a map to store frequencies of (A_i - i)
    map<int, long long> freq;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        // Calculate B_i = A_i - (i + 1)
        // Note: i is 0-indexed, so we use (i + 1) for 1-based indexing
        int transformed_val = val - (i + 1);
        freq[transformed_val]++;
    }
    
    long long total_pairs = 0;
    for (auto const& [val, count] : freq) {
        if (count >= 2) {
            // Number of ways to choose 2 indices from 'count' occurrences
            total_pairs += (count * (count - 1)) / 2;
        }
    }
    
    cout << total_pairs << "\n";
}

int main() {
    // Fast I/O for performance
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