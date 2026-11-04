# [Find Multiset State (ARRAYSTATE)](https://www.codechef.com/problems/ARRAYSTATE)

- **Difficulty Rating**: 1119
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an initially sorted array $A$ of $N$ integers, we perform $K$ operations. In each operation, we remove the current minimum and maximum elements from the multiset and insert their sum back into the multiset. We need to output the final state of the multiset in non-decreasing order after $K$ operations.

## Intuition & Mathematical Observation
1. **Data Structure Selection**: Since the array is initially sorted, the smallest elements are at the beginning and the largest are at the end. As we perform operations, we generate new sums. Because the sum of the minimum and maximum is generally larger than the existing elements, the new values will naturally tend to be larger.
2. **Managing the Multiset**: We can maintain the original elements in a `std::deque` (which allows efficient removal from both ends) and the newly generated sums in a `std::queue`. 
3. **Finding Min/Max**: In each step, the global minimum must be either the front of the `deque` or the front of the `queue`. Similarly, the global maximum must be either the back of the `deque` or the back of the `queue`. By comparing these, we can extract the min and max in $O(1)$ time per operation.
4. **Final State**: After $K$ operations, we collect all remaining elements from the `deque` and the `queue`, sort them, and print the result.

## Complexity Analysis
- **Time Complexity**: $O(K + N \log N)$. We perform $K$ operations, each taking $O(1)$ time. Finally, we sort the remaining $N$ elements, which takes $O(N \log N)$. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$, as we store the $N$ elements in a deque and a queue.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is initially sorted.
 * In each operation, we remove the smallest element and the largest element,
 * and append their sum to the back.
 * 
 * We use a deque to manage the original array and a queue to store the 
 * newly generated sums.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Deque to store the original elements
    deque<long long> dq;
    for (long long x : A) {
        dq.push_back(x);
    }

    // Queue to store the newly generated sums
    queue<long long> q;

    for (int i = 0; i < K; ++i) {
        long long min_val, max_val;

        // Get min: compare front of dq and front of q
        if (q.empty() || (!dq.empty() && dq.front() <= q.front())) {
            min_val = dq.front();
            dq.pop_front();
        } else {
            min_val = q.front();
            q.pop();
        }

        // Get max: compare back of dq and back of q
        if (q.empty() || (!dq.empty() && dq.back() >= q.back())) {
            max_val = dq.back();
            dq.pop_back();
        } else {
            max_val = q.back();
            q.pop();
        }

        q.push(min_val + max_val);
    }

    // Collect remaining elements
    vector<long long> result;
    while (!dq.empty()) {
        result.push_back(dq.front());
        dq.pop_front();
    }
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    // Sort the final collection
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
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