# [Chef and IPC Certificates (IPCCERT)](https://www.codechef.com/problems/IPCCERT)

- **Difficulty Rating**: 922
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is organizing an IPC certification program. To receive a certificate, a student must satisfy two conditions:
1. The total time spent watching lectures must be at least $M$ minutes.
2. The number of questions asked by the student must be no more than 10.

Given $N$ students, each having watched $K$ lectures (with specific durations) and asked $Q$ questions, determine how many students are eligible for the certificate.

## Intuition & Mathematical Observation
The problem is a straightforward simulation. For each student:
1. We are given $K$ integers representing the duration of each lecture. We calculate the sum of these durations to get the `total_time`.
2. We are given an integer $Q$ representing the number of questions asked.
3. We apply the logical condition: `(total_time >= M) AND (Q <= 10)`.
4. We maintain a counter and increment it whenever a student satisfies both conditions.

Since the constraints are small enough ($N, K \le 100$), a simple linear scan through the input is efficient and sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N \times K)$, where $N$ is the number of students and $K$ is the number of lectures per student. We iterate through every lecture duration once.
- **Space Complexity**: $O(1)$, as we only store the running sum and current variables for each student, requiring constant extra space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: IPCCERT
 * Time Complexity: O(N * K)
 * Space Complexity: O(1)
 * 
 * Logic:
 * For each student, we calculate the sum of lecture times T_{i,j}.
 * We check two conditions:
 * 1. Total time >= M
 * 2. Questions asked Q_i <= 10
 * If both are true, the student is eligible.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    int K;

    if (!(cin >> N >> M >> K)) return 0;

    int eligible_count = 0;

    for (int i = 0; i < N; ++i) {
        long long total_time = 0;
        for (int j = 0; j < K; ++j) {
            long long t;
            cin >> t;
            total_time += t;
        }
        
        long long Q;
        cin >> Q;

        // Check criteria:
        // 1. Total time watched >= M
        // 2. Questions asked <= 10
        if (total_time >= M && Q <= 10) {
            eligible_count++;
        }
    }

    cout << eligible_count << "\n";

    return 0;
}
```