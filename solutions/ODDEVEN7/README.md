# [Odd Even (ODDEVEN7)](https://www.codechef.com/problems/ODDEVEN7)

- **Difficulty Rating**: 877
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to find the length of the longest subsequence that has alternating parity (i.e., the parity of adjacent elements must be different).

## Intuition & Mathematical Observation
To form an alternating sequence, we need to alternate between odd and even numbers. Let $O$ be the count of odd numbers and $E$ be the count of even numbers in the array.

1.  **Case 1: $O = E$**
    We can use all elements in the array by arranging them as $O, E, O, E, \dots$ or $E, O, E, O, \dots$. The total length is $O + E$.
2.  **Case 2: $O \neq E$**
    We are limited by the count of the minority parity. If we have $k$ elements of one parity, we can at most use $k+1$ elements of the other parity to maintain the alternating property (e.g., if we have 2 odds and 5 evens, we can pick $E, O, E, O, E$, which uses 2 odds and 3 evens).
    The total length is $2 \times \min(O, E) + 1$.

By combining these, we can determine the maximum length for any given input.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the parities.
- **Space Complexity**: $O(1)$, as we only store the counts of odd and even numbers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A "good" array has alternating parity (Odd, Even, Odd, Even... or Even, Odd, Even, Odd...).
 * Let 'odd_count' be the number of odd integers in the input array.
 * Let 'even_count' be the number of even integers in the input array.
 * 
 * To form an alternating sequence:
 * 1. If odd_count == even_count, we can use all elements. Total = 2 * odd_count.
 * 2. If odd_count != even_count, we can take the smaller count and match it with 
 *    the larger count. Total = 2 * min(odd_count, even_count) + 1.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == even_count) {
        cout << odd_count + even_count << "\n";
    } else {
        cout << 2 * min(odd_count, even_count) + 1 << "\n";
    }
}

int main() {
    // Fast I/O setup
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