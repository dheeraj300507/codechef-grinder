# [Rhythmic Door (RHYDOOR)](https://www.codechef.com/problems/RHYDOOR)

- **Difficulty Rating**: 687
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to process a sequence of button presses represented by a string. We need to determine how many times a "door opens." A door opens if the same button is pressed 3 consecutive times. Once the door opens, the streak resets, and we start counting again from the next character.

## Intuition & Mathematical Observation
The core of the problem is to maintain a running "streak" of identical consecutive characters. 

1. **Tracking the Streak**: We iterate through the string while keeping track of the `last_char` seen and the current `streak` length.
2. **Resetting Logic**: 
   - If the current character matches the `last_char`, we increment the `streak`.
   - If it does not match, we reset the `streak` to 1 and update the `last_char`.
3. **Triggering the Event**: Whenever the `streak` hits 3, we increment our total count of door openings. Crucially, after the door opens, we must reset the `streak` to 0 and clear the `last_char` (or set it to a null character) so that the next character starts a fresh sequence, preventing the code from counting overlapping sequences incorrectly.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the input string.
- **Space Complexity**: $O(N)$ to store the input string. If we processed the input character-by-character, this could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count how many times a button is pressed 3 consecutive times.
 * Once a streak of 3 is reached, the counter resets.
 * 
 * Approach:
 * Iterate through the string and maintain a current streak count.
 * If the current character matches the previous one, increment the streak.
 * If it doesn't match, reset the streak to 1.
 * If the streak reaches 3, increment the answer and reset the streak to 0.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count = 0;
    int streak = 0;
    char last_char = '\0';

    for (int i = 0; i < N; ++i) {
        if (S[i] == last_char) {
            streak++;
        } else {
            streak = 1;
            last_char = S[i];
        }

        if (streak == 3) {
            count++;
            streak = 0;
            last_char = '\0'; // Reset after opening
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O
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