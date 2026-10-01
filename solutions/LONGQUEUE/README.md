# [Long Queue (LONGQUEUE)](https://www.codechef.com/problems/LONGQUEUE)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
Sushil is standing at the end of a queue of $N$ people, where each person has a specific wealth value. Sushil can "bully" the person directly in front of him if that person's wealth is less than or equal to half of Sushil's wealth (i.e., $A_i \le \lfloor \frac{A_{N-1}}{2} \rfloor$). When he bullies someone, he swaps places with them. He continues this process until he either reaches the front of the queue or encounters someone he cannot bully. We need to find his final position in the queue.

## Intuition & Mathematical Observation
1. **The Condition**: The problem states Sushil moves forward only if the person directly in front of him satisfies the condition $A_i \le \frac{A_{N-1}}{2}$.
2. **The Process**: Since Sushil is at the end (index $N-1$), we start checking from the person at index $N-2$ and move backwards towards index $0$.
3. **Stopping Criterion**: As soon as we find a person whose wealth is greater than half of Sushil's wealth, the condition fails. Because Sushil can only swap with the person *directly* in front of him, he cannot "jump over" stronger people. Therefore, the process terminates immediately upon encountering the first person who does not satisfy the condition.
4. **Implementation**: We maintain a counter for his position, starting at $N$. For every person from $N-2$ down to $0$, if the condition is met, we decrement the position. If not, we `break` the loop.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array at most once.
- **Space Complexity**: $O(N)$ to store the wealth values of the people in the queue.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Sushil is at the N-th position (index N-1 in 0-indexed array).
 * His wealth is A[N-1].
 * He can bully the person directly in front of him if that person's wealth 
 * is <= (Sushil's wealth / 2).
 * Since he only bullies the person directly in front of him, we check from 
 * the person at index N-2 down to 0.
 * As soon as he encounters someone he cannot bully, he stops moving forward.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int sushil_wealth = A[N - 1];
    int current_pos = N; // 1-based position

    // Check people from the one directly in front of Sushil backwards
    for (int i = N - 2; i >= 0; --i) {
        // Condition: wealth <= sushil_wealth / 2
        // Using integer division as per problem statement (A_i <= X/2)
        if (A[i] <= (sushil_wealth / 2)) {
            current_pos--;
        } else {
            // Cannot bully this person, stop moving forward
            break;
        }
    }

    cout << current_pos << "\n";
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