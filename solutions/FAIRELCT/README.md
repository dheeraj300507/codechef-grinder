# [Fair Elections (FAIRELCT)](https://www.codechef.com/problems/FAIRELCT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
John Jackson and Jack Johnson are competing in an election. John has $N$ packs of votes and Jack has $M$ packs of votes. John wants to win the election, meaning his total number of votes must be strictly greater than Jack's. We are allowed to swap any pack of votes from John with any pack of votes from Jack. The goal is to find the minimum number of swaps required to make John's total votes greater than Jack's, or determine if it is impossible.

## Intuition & Mathematical Observation
To maximize John's total votes while minimizing the number of swaps, we should adopt a **Greedy Strategy**:
1. **Identify the Bottleneck**: John needs to increase his sum. To get the maximum increase in his total with a single swap, he should always give away his smallest pack of votes and receive Jack's largest pack of votes.
2. **Sorting**: By sorting John's packs in ascending order and Jack's packs in descending order, we ensure that at each step $i$, we are comparing the smallest available pack from John ($A[i]$) with the largest available pack from Jack ($B[i]$).
3. **Condition for Swapping**: A swap is only beneficial if $A[i] < B[i]$. If $A[i] \ge B[i]$, swapping will either decrease John's total or keep it the same, which is counter-productive.
4. **Termination**: 
   - If at any point John's total sum becomes strictly greater than Jack's, we stop and return the number of swaps performed.
   - If we exhaust all possible beneficial swaps (or run out of packs) and John's sum is still not greater than Jack's, it is impossible to win, so we return -1.

## Complexity Analysis
- **Time Complexity**: $O(N \log N + M \log M)$ per test case, where $N$ and $M$ are the number of vote packs for John and Jack respectively. This is dominated by the sorting of the two arrays. The subsequent linear scan takes $O(\min(N, M))$.
- **Space Complexity**: $O(N + M)$ to store the vote packs in vectors.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * We want to minimize the number of swaps.
 * To maximize John's total votes while minimizing swaps, we should always swap
 * the smallest pack from A with the largest pack from B, provided the smallest
 * pack from A is smaller than the largest pack from B.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    // Sort A ascending, B descending to greedily pick best swaps
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int swaps = 0;
    int i = 0;
    while (sumA <= sumB) {
        // If we run out of elements to swap or the smallest A is not smaller than largest B
        if (i >= N || i >= M || A[i] >= B[i]) {
            cout << -1 << "\n";
            return;
        }
        
        // Perform swap
        sumA = sumA - A[i] + B[i];
        sumB = sumB - B[i] + A[i];
        swaps++;
        i++;
    }

    cout << swaps << "\n";
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