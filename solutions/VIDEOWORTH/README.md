# [Worth of a Video (VIDEOWORTH)](https://www.codechef.com/problems/VIDEOWORTH)

- **Difficulty Rating**: 382
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total "worth" of a video given its duration in seconds ($S$). We are provided with the following constants:
*   The video plays at a rate of **24 frames per second**.
*   Each individual frame is worth **1000 words**.

We need to output the total number of words for a video of $S$ seconds.

## Intuition & Mathematical Observation
To find the total worth, we perform a simple multiplication based on the given rates:
1.  **Total Frames**: Since there are 24 frames per second, a video of $S$ seconds contains $S \times 24$ frames.
2.  **Total Worth**: Since each frame is worth 1000 words, the total worth is $(S \times 24) \times 1000$.

Simplifying the expression:
$$\text{Total Worth} = S \times 24,000$$

Given the constraints ($S \le 100$), the maximum possible result is $100 \times 24,000 = 2,400,000$, which fits well within a standard 32-bit integer. However, using `long long` is a safe practice to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Frames per second = 24
 * - Worth per frame = 1000 words
 * - Duration = S seconds
 * - Total frames = S * 24
 * - Total worth = (S * 24) * 1000 = S * 24000
 */

int main() {
    // Fast I/O setup for efficiency
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long s;
        cin >> s;
        
        // Calculate total worth: S seconds * 24 frames/sec * 1000 words/frame
        long long total_worth = s * 24 * 1000;
        
        cout << total_worth << "\n";
    }

    return 0;
}
```