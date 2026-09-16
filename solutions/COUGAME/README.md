# [Couple Game (COUGAME)](https://www.codechef.com/problems/COUGAME)

- **Difficulty Rating**: 347
- **Solved in**: 1 attempt(s)

## Problem Summary
In a group consisting of $G$ girls and $B$ boys, we need to form as many boy-girl pairs as possible. Each pair must consist of exactly one boy and one girl. Given that $B > G$, we need to calculate the number of boys who will remain unpaired after forming the maximum possible number of teams.

## Intuition & Mathematical Observation
- Each team requires exactly one girl and one boy.
- Since there are $G$ girls available, we can form at most $G$ teams (assuming $B > G$).
- Each of these $G$ teams will consume exactly one boy.
- Therefore, the total number of boys used is $G$.
- The number of boys remaining is the total number of boys minus the number of boys used in teams:
  $$\text{Remaining Boys} = B - G$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant time subtraction operation for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have G girls and B boys, where B > G.
 * Each team consists of exactly 1 girl and 1 boy.
 * To maximize the number of teams, we pair each girl with one boy.
 * Since there are G girls, we can form at most G teams.
 * Each team uses 1 boy, so G boys are used.
 * The number of boys remaining is B - G.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long g, b;
        cin >> g >> b;
        
        // The number of boys who cannot participate is the total boys 
        // minus the number of girls (since each girl forms one team).
        long long result = b - g;
        
        cout << result << "\n";
    }

    return 0;
}
```