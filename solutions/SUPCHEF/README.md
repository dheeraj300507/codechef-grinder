# [The Preparations (SUPCHEF)](https://www.codechef.com/problems/SUPCHEF)

- **Difficulty Rating**: 823
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $M$ minutes remaining until his exam starts. He wants to watch a TV series consisting of $N$ episodes, where each episode lasts $K$ minutes. The goal is to determine if Chef can finish watching all $N$ episodes **strictly before** the exam begins.

## Intuition & Mathematical Observation
To determine if Chef can finish the series in time, we need to calculate the total time required to watch all episodes:
$$\text{Total Duration} = N \times K$$

The problem specifies that Chef must finish **strictly before** the exam starts. This implies that the total duration must be strictly less than the time remaining ($M$):
$$\text{Total Duration} < M$$

If $N \times K < M$, output `YES`. Otherwise, output `NO`.

**Note on Constraints:** 
While $N$ and $K$ are up to $10^4$, their product can reach $10^8$. While this fits within a standard 32-bit `int`, using `long long` is a best practice in competitive programming to prevent potential overflow issues if constraints were slightly larger.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a comparison, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has M minutes until the exam.
 * Season-1 has N episodes, each of duration K minutes.
 * Total time required = N * K.
 * The condition is to finish "strictly before" the exam starts.
 * This means: Total time < M.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long m, n, k;
        cin >> m >> n >> k;
        
        // Calculate total duration required
        long long total_duration = n * k;
        
        // Check if total duration is strictly less than M
        if (total_duration < m) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```