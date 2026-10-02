# [Big Achiever (BIG)](https://www.codechef.com/problems/BIG)

- **Difficulty Rating**: 699
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers representing the scores of students, a student is considered a "Big Achiever" if their score is strictly greater than the scores of all students who appeared before them in the sequence. The first student is always considered a Big Achiever. We need to output a binary sequence where `1` indicates a Big Achiever and `0` indicates otherwise.

## Intuition & Mathematical Observation
The problem asks us to track the maximum value encountered so far as we iterate through the array. 

1. **The First Student**: Since there are no students before the first one, the condition is satisfied by default.
2. **Subsequent Students**: For any student at index $i > 0$, they are a Big Achiever if $A[i] > \max(A[0], A[1], \dots, A[i-1])$.
3. **Optimization**: Instead of re-calculating the maximum for every index (which would be $O(N^2)$), we can maintain a variable `current_max` that stores the highest score seen so far. As we iterate through the array:
   - If the current element is greater than `current_max`, the student is a Big Achiever, and we update `current_max` to the current element's value.
   - Otherwise, the student is not a Big Achiever.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single pass through the array of size $N$.
- **Space Complexity**: $O(N)$ to store the input array (this can be reduced to $O(1)$ if we process the input elements one by one without storing them).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A student i is happy if A[i] > max(A[0], A[1], ..., A[i-1]).
 * For the first student (i=0), there are no students before them, 
 * so the condition is vacuously true.
 * 
 * We maintain a running maximum of the scores seen so far.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int current_max = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > current_max) {
            cout << 1 << (i == N - 1 ? "" : " ");
            current_max = A[i];
        } else {
            cout << 0 << (i == N - 1 ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```