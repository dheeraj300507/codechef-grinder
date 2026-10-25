# [Nearly Equal (SAMESAME)](https://www.codechef.com/problems/SAMESAME)

- **Difficulty Rating**: 946
- **Solved in**: 3 attempt(s)

## Problem Summary
Given two strings $A$ (length $N$) and $B$ (length $M$), where $M \le N$, we need to find the minimum Hamming distance between string $B$ and any substring of $A$ that has length $M$. The Hamming distance is defined as the number of positions at which the corresponding characters are different.

## Intuition & Mathematical Observation
Since the constraints are small ($N, M \le 100$), we can use a **sliding window** approach:
1. A substring of $A$ with length $M$ can start at any index $i$ from $0$ to $N - M$.
2. For every possible starting position $i$, we extract the substring $A[i \dots i+M-1]$.
3. We compare this substring character-by-character with string $B$.
4. We count the number of mismatches (Hamming distance) for each window.
5. The answer is the minimum count obtained across all possible windows.

This brute-force approach is efficient enough because the total number of operations per test case is roughly $N \times M$, which is at most $100 \times 100 = 10,000$ operations—well within the time limit for typical competitive programming environments.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times M)$, where $T$ is the number of test cases, $N$ is the length of string $A$, and $M$ is the length of string $B$. Given $N, M \le 100$, this performs approximately $10^4$ operations per test case.
- **Space Complexity**: $O(N + M)$ to store the input strings.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: SAMESAME
 * Approach: Brute force sliding window.
 * Complexity: O(T * N * M), where N, M <= 100.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;

    int min_hamming = M; // Maximum possible Hamming distance is M

    // Iterate through all possible starting positions of the substring in A
    for (int i = 0; i <= N - M; ++i) {
        int current_hamming = 0;
        // Compare substring A[i...i+M-1] with B
        for (int j = 0; j < M; ++j) {
            if (A[i + j] != B[j]) {
                current_hamming++;
            }
        }
        // Update the minimum Hamming distance found so far
        if (current_hamming < min_hamming) {
            min_hamming = current_hamming;
        }
    }

    cout << min_hamming << endl;
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