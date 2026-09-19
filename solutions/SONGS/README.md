# [Playlist (SONGS)](https://www.codechef.com/problems/SONGS)

- **Difficulty Rating**: 489
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a playlist consisting of three songs: A, B, and C, which repeat in that specific order (A, B, C, A, B, C, ...). Given the total duration of the playlist $N$ and the duration of each individual song $X$, determine how many times song C is completed.

## Intuition & Mathematical Observation
1. **Calculate Total Songs**: Since every song has a duration of $X$, the total number of songs played in duration $N$ is given by:
   $$\text{total\_songs} = \lfloor N / X \rfloor$$
2. **Identify the Pattern**: The songs repeat in a cycle of 3: $(A, B, C)$.
3. **Determine Occurrences**: 
   - In every full cycle of 3 songs, song C appears exactly once.
   - If we have $K$ total songs, the number of full cycles completed is $\lfloor K / 3 \rfloor$.
   - Any remainder songs (1 or 2) after the full cycles are either just A, or A and B. In neither of these cases is song C completed.
4. **Conclusion**: The number of times song C is completed is simply the integer division of the total number of songs by 3.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each song has duration X.
 * The playlist consists of 3 songs: A, B, C.
 * Total duration of one full cycle (A -> B -> C) is 3 * X.
 * 
 * The number of times song C is completed is simply the total number of 
 * songs played divided by 3 (integer division).
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // Total number of songs completed
        long long total_songs = n / x;
        
        // Each cycle of 3 songs contains exactly one C
        long long count_c = total_songs / 3;
        
        cout << count_c << "\n";
    }
    
    return 0;
}
```