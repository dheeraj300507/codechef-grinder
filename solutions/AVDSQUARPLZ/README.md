# [Avoid Squares Please (AVDSQUARPLZ)](https://www.codechef.com/problems/AVDSQUARPLZ)

- **Difficulty Rating**: 960
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to arrange the numbers from $1$ to $N$ in a sequence such that the product of any two adjacent elements is **not** a perfect square.

## Intuition & Mathematical Observation
The core challenge is to avoid adjacent pairs $(a, b)$ such that $a \times b = k^2$. 

A simple and effective construction is to separate the numbers into two groups: **Even numbers** and **Odd numbers**. By printing all even numbers in descending order followed by all odd numbers in descending order, we significantly reduce the likelihood of creating a perfect square product:

1.  **Within the Even group**: Adjacent products are of the form $(2k) \times (2k-2) = 4(k^2 - k)$. For this to be a perfect square, $k^2 - k$ must be a perfect square, which only happens when $k=1$ (resulting in $0$, which is not possible here as $k \ge 1$).
2.  **Within the Odd group**: Adjacent products are of the form $(2k+1) \times (2k-1) = 4k^2 - 1$. Since $4k^2 - 1$ is always one less than a perfect square ($4k^2$), it can never be a perfect square itself for $k > 0$.
3.  **Transition**: The transition between the last even number and the first odd number is also unlikely to form a square, and for the given constraints ($N \le 500$), this heuristic holds true.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the numbers from $1$ to $N$ exactly once to categorize them and once more to print them.
- **Space Complexity**: $O(N)$ to store the even and odd numbers in vectors before printing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to arrange numbers from 1 to N such that no two adjacent elements
 * have a product that is a perfect square.
 * 
 * Strategy: Print all even numbers in descending order, 
 * followed by all odd numbers in descending order.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<int> evens;
    vector<int> odds;
    
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) evens.push_back(i);
        else odds.push_back(i);
    }
    
    // Print evens descending, then odds descending
    bool first = true;
    for (int i = evens.size() - 1; i >= 0; --i) {
        if (!first) cout << " ";
        cout << evens[i];
        first = false;
    }
    for (int i = odds.size() - 1; i >= 0; --i) {
        if (!first) cout << " ";
        cout << odds[i];
        first = false;
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