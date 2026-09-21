# [Chef and Races (CHEFRACES)](https://www.codechef.com/problems/CHEFRACES)

- **Difficulty Rating**: 745
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef participates in two races, $X$ and $Y$. His rival participates in two races, $A$ and $B$. Chef wins a race if his rival is not participating in that specific race. We need to calculate the total number of gold medals (wins) Chef earns.

## Intuition & Mathematical Observation
To determine if Chef wins a race, we simply need to check if his race ID is absent from the rival's set of race IDs $\{A, B\}$.

1. **Race X**: Chef wins if $X \neq A$ AND $X \neq B$.
2. **Race Y**: Chef wins if $Y \neq A$ AND $Y \neq B$.

By evaluating these two conditions independently and incrementing a counter for each true condition, we obtain the total number of gold medals.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef participates in two races: X and Y.
 * The rival participates in two races: A and B.
 * Chef can win a race if the rival is not participating in that specific race.
 * 
 * We need to count how many of {X, Y} are NOT in {A, B}.
 */

void solve() {
    int X, Y, A, B;
    if (!(cin >> X >> Y >> A >> B)) return;

    int gold_medals = 0;

    // Check if Chef wins race X
    if (X != A && X != B) {
        gold_medals++;
    }

    // Check if Chef wins race Y
    if (Y != A && Y != B) {
        gold_medals++;
    }

    cout << gold_medals << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```