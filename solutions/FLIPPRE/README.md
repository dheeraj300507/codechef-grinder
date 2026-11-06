# [Flip Prefix (FLIPPRE)](https://www.codechef.com/problems/FLIPPRE)

- **Difficulty Rating**: 1148
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we are allowed to perform an operation: flip a prefix $S[1 \dots X]$ if and only if the number of '0's in the prefix equals the number of '1's. Flipping means changing all '0's to '1's and all '1's to '0's within that prefix. We need to determine the total number of distinct binary strings that can be generated starting from the initial string $S$.

## Intuition & Mathematical Observation
1. **Defining the Balance**: Let $count_0(i)$ and $count_1(i)$ be the number of '0's and '1's in the prefix $S[1 \dots i]$, respectively. A prefix $S[1 \dots i]$ is "flippable" if $count_0(i) = count_1(i)$.
2. **Independent Operations**: Let the indices where $count_0(i) = count_1(i)$ be $i_1, i_2, \dots, i_k$. Each such index represents a point where the prefix can be flipped. 
3. **Reachable States**: When we flip a prefix $S[1 \dots i_j]$, we change the balance of the string. However, because the condition $count_0(i) = count_1(i)$ is based on the prefix sum, performing a flip at index $i_j$ effectively toggles the state of the string up to that point. Since each of the $k$ valid indices can either be flipped or not flipped independently, and each combination results in a unique string configuration, the total number of reachable strings is $2^k$.
4. **Implementation**: We iterate through the string once, maintaining a running count of '0's and '1's. Every time the counts are equal, we increment our counter $k$. The final answer is $2^k$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single pass through the string to count the valid prefix indices.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A prefix S[1...X] is flippable if count0(X) == count1(X).
 * Each such index i where count0(i) == count1(i) provides an independent 
 * choice to flip or not flip the prefix. 
 * With k such indices, there are 2^k possible reachable strings.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count0 = 0;
    int count1 = 0;
    long long k = 0;

    // Count how many prefixes have an equal number of 0s and 1s
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') count0++;
        else count1++;

        if (count0 == count1) {
            k++;
        }
    }

    // The number of reachable strings is 2^k.
    // Using 1LL to ensure the shift operation is performed on a long long.
    long long ans = 1LL << k;
    cout << ans << "\n";
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