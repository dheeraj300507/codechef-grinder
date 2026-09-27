# [Passing Marks (CUTOFF)](https://www.codechef.com/problems/CUTOFF)

- **Difficulty Rating**: 855
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ students with distinct scores $A_i$, we are told that exactly $X$ students passed the exam. A student passes if their score is strictly greater than the passing mark $P$. We need to find the maximum possible integer value for $P$ such that exactly $X$ students pass.

## Intuition & Mathematical Observation
To ensure exactly $X$ students pass, we must identify the $X$ students with the highest scores. 
1. If we sort the scores in descending order ($S_1 > S_2 > \dots > S_N$), the students who pass are those with scores $S_1, S_2, \dots, S_X$.
2. The student with the lowest passing score is the one at index $X-1$ (using 0-based indexing), which is $S_X$.
3. For this student to pass, the passing mark $P$ must be strictly less than $S_X$ ($P < S_X$).
4. To maximize $P$ while ensuring that the student with the $(X+1)$-th highest score ($S_{X+1}$) does not pass, we set $P$ to be exactly one less than the $X$-th highest score.
5. Therefore, the maximum passing mark is $S_X - 1$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting of the array of scores.
- **Space Complexity**: $O(N)$ to store the scores of the $N$ students.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N students with distinct scores A_i.
 * Exactly X students pass the test.
 * A student passes if their score > passing_mark.
 * We want the maximum possible passing_mark.
 * 
 * To have exactly X students pass, we need the X students with the highest 
 * scores to be the ones who pass.
 * If we sort the scores in descending order: S_1 > S_2 > ... > S_N.
 * The students who pass are the ones with scores S_1, S_2, ..., S_X.
 * The student who barely passed is the one with the X-th highest score (S_X).
 * The maximum P is S_X - 1.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the X-th highest score
    sort(A.begin(), A.end(), greater<int>());

    // The X-th student (index X-1) is the one with the lowest score among those who passed.
    // The maximum passing mark P such that this student passes is A[X-1] - 1.
    int passing_mark = A[X - 1] - 1;
    cout << passing_mark << "\n";
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