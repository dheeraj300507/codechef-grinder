# [Coldplay (SLOOP)](https://www.codechef.com/problems/SLOOP)

- **Difficulty Rating**: 854
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is going on a trip that lasts for $M$ minutes. He wants to listen to a song that lasts for $S$ minutes repeatedly. The goal is to determine the maximum number of times the song can be played completely within the total duration of the trip ($M$).

## Intuition & Mathematical Observation
The problem asks for the maximum number of full repetitions of a song of length $S$ that can fit into a total time $M$. 

Mathematically, this is a classic application of integer division. If we divide the total time $M$ by the song duration $S$, the quotient represents the number of times the song fits entirely into the duration. Any remainder represents the time left over that is insufficient to play the song again. 

In C++, performing `M / S` using integer types automatically performs this floor division, which is exactly what is required.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a single constant-time division operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a trip of duration M minutes.
 * The song has a duration of S minutes.
 * We need to find how many times the song can be played completely within M minutes.
 * This is equivalent to finding the floor of the division M / S.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= M <= 100
 * 1 <= S <= 10
 * 
 * Since M and S are small, standard integer division will work perfectly.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long m, s;
        cin >> m >> s;
        
        // The number of complete plays is the integer division of M by S.
        // If M < S, the result is 0, which is handled correctly by integer division.
        long long result = m / s;
        
        cout << result << "\n";
    }
    
    return 0;
}
```