# [Typing World (TYPWRL)](https://www.codechef.com/problems/TYPWRL)

- **Difficulty Rating**: 807
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a string $S$ representing a word to be typed and a string $L$ containing all the characters typed by the left hand. Any character not present in $L$ is typed by the right hand. The goal is to find the length of the longest contiguous sequence of characters typed by the same hand.

## Intuition & Mathematical Observation
The problem asks for the maximum length of a "streak" of characters typed by the same hand. 
1. **Hand Identification**: Since we need to check if a character belongs to the left hand frequently, we can map the characters in string $L$ to a boolean array of size 26. This allows for $O(1)$ lookup time.
2. **Streak Tracking**: We iterate through the string $S$ character by character. For each character, we determine if it is typed by the 'L' (left) or 'R' (right) hand.
3. **State Management**: We maintain a `current_streak` counter. If the current character's hand matches the previous character's hand, we increment the counter. If it differs, we reset the counter to 1. We keep a `max_streak` variable to store the highest value reached during the iteration.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$, where $N$ is the length of the string $S$ and $M$ is the length of the string $L$. We iterate through $L$ once to build the lookup table and through $S$ once to calculate the streaks.
- **Space Complexity**: $O(1)$ (or $O(\Sigma)$ where $\Sigma=26$), as the boolean array for character lookup is of constant size regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Typing World
 * Approach:
 * 1. Store the left-hand keys in a boolean array for O(1) lookup.
 * 2. Iterate through the string S. For each character, determine if it's typed by the left hand (L) or right hand (R).
 * 3. Keep track of the current hand being used and the current streak length.
 * 4. If the current character's hand matches the previous one, increment the streak.
 * 5. If it differs, reset the streak to 1 and update the current hand.
 * 6. Maintain a global maximum of these streaks.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string S, L;
    cin >> S >> L;

    // Use a boolean array to mark left-hand keys for O(1) access
    bool is_left[26] = {false};
    for (char c : L) {
        is_left[c - 'a'] = true;
    }

    int max_streak = 0;
    int current_streak = 0;
    char last_hand = ' '; // 'L' for left, 'R' for right

    for (int i = 0; i < N; ++i) {
        char current_hand = is_left[S[i] - 'a'] ? 'L' : 'R';

        if (current_hand == last_hand) {
            current_streak++;
        } else {
            current_streak = 1;
            last_hand = current_hand;
        }

        if (current_streak > max_streak) {
            max_streak = current_streak;
        }
    }

    cout << max_streak << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```