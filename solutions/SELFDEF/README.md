# [Self Defence Training (SELFDEF)](https://www.codechef.com/problems/SELFDEF)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine how many people in a given group are eligible for a self-defense training program. A person is eligible if their age $A_i$ satisfies the condition: $10 \le A_i \le 60$. Given $N$ ages, we need to count how many individuals fall within this inclusive range.

## Intuition & Mathematical Observation
The problem requires a simple filtering process. For each test case:
1. We read the total number of people $N$.
2. We iterate through the list of $N$ ages.
3. For each age, we apply a conditional check: `age >= 10 && age <= 60`.
4. We maintain a counter that increments whenever the condition is met.
5. Since we only need the final count, we do not need to store the ages in an array, allowing us to process the input in $O(1)$ auxiliary space.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of people per test case. We iterate through every age exactly once.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the count and the current age, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Self Defence Training
 * The condition for eligibility is age A_i such that 10 <= A_i <= 60.
 * We iterate through each age and count how many satisfy this condition.
 * Time Complexity: O(T * N)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            // Check if age is within the inclusive range [10, 60]
            if (age >= 10 && age <= 60) {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
```