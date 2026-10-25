# [Unequal Shuffle (UNQSHF)](https://www.codechef.com/problems/UNQSHF)

- **Difficulty Rating**: 726
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $A$ and $B$ of length $N$ consisting only of characters 'a' and 'b', determine if it is possible to shuffle $A$ and $B$ independently such that for all indices $i$ ($0 \le i < N$), $A[i] \neq B[i]$.

## Intuition & Mathematical Observation
To satisfy the condition $A[i] \neq B[i]$ for all $i$, we must ensure that every character in $A$ is paired with a different character in $B$. Since the strings only contain 'a' and 'b', this implies:
1. Every 'a' in $A$ must be paired with a 'b' in $B$.
2. Every 'b' in $A$ must be paired with an 'a' in $B$.

Let $countA_a$ be the number of 'a's in $A$, and $countB_b$ be the number of 'b's in $B$. For the condition to hold, the number of 'a's in $A$ must exactly match the number of 'b's in $B$ to ensure every 'a' has a corresponding 'b' to pair with.

Mathematically:
- $countA_a = countB_b$
- $countA_b = countB_a$

Since the total length of both strings is $N$, these two conditions are equivalent. If $countA_a = countB_b$, then $N - countA_a = N - countB_b$, which simplifies to $countA_b = countB_a$. Therefore, we only need to verify if the count of 'a's in $A$ equals the count of 'b's in $B$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the strings. We iterate through each string exactly once to count the characters.
- **Space Complexity**: $O(N)$ to store the input strings. If we processed the input character by character, this could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To satisfy A[i] != B[i], every 'a' in A must be paired with a 'b' in B,
 * and every 'b' in A must be paired with an 'a' in B.
 * This is possible if and only if the number of 'a's in A equals the 
 * number of 'b's in B.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA_a = 0;
    for (char c : A) {
        if (c == 'a') countA_a++;
    }

    int countB_b = 0;
    for (char c : B) {
        if (c == 'b') countB_b++;
    }

    if (countA_a == countB_b) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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