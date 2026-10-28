# [Maximum Score (MAXSCORE7)](https://www.codechef.com/problems/MAXSCORE7)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary array $A$ of even length $N$, we perform $N/2$ operations. In each operation, we select two adjacent elements, add the absolute difference of these elements to our total score, and remove them from the array. The goal is to maximize the total score obtained after $N/2$ operations.

## Intuition & Mathematical Observation
Since the array consists only of $0$s and $1$s, the absolute difference $|A_i - A_{i+1}|$ can only be:
- $1$ if the pair is $(0, 1)$ or $(1, 0)$.
- $0$ if the pair is $(0, 0)$ or $(1, 1)$.

To maximize the total score, we want to maximize the number of pairs consisting of one $0$ and one $1$. 
- Let $c_0$ be the total count of $0$s in the array.
- Let $c_1$ be the total count of $1$s in the array.

Each operation that yields a score of $1$ consumes exactly one $0$ and one $1$. Because we can remove any adjacent pair, we can strategically remove elements to bring any $0$ and $1$ together. Therefore, the maximum number of $(0, 1)$ pairs we can form is limited by the count of the minority element. Specifically, we can form exactly $\min(c_0, c_1)$ pairs that contribute $1$ to the score. Any remaining elements will necessarily be paired with their own kind (e.g., $0$ with $0$ or $1$ with $1$), contributing $0$ to the score.

Thus, the maximum score is simply $\min(c_0, c_1)$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to count the occurrences of $0$s and $1$s.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a binary array A of length N (even).
 * We perform N/2 operations. In each operation, we pick adjacent elements A_i, A_{i+1},
 * add |A_i - A_{i+1}| to the score, and remove them.
 * 
 * Since the array is binary (0s and 1s), |A_i - A_{i+1}| is 1 if the pair is (0, 1) or (1, 0),
 * and 0 if the pair is (0, 0) or (1, 1).
 * 
 * To maximize the score, we want to pair as many 0s with 1s as possible.
 * The maximum score is simply min(count of 0s, count of 1s).
 */

void solve() {
    int N;
    cin >> N;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            c0++;
        } else {
            c1++;
        }
    }
    // The answer is the number of pairs of (0, 1) we can form.
    cout << min(c0, c1) << "\n";
}

int main() {
    // Fast I/O
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