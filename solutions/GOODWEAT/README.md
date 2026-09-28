# [Good Weather (GOODWEAT)](https://www.codechef.com/problems/GOODWEAT)

- **Difficulty Rating**: 835
- **Solved in**: 1 attempt(s)

## Problem Summary
We are provided with 7 integers representing the weather for each day of the week, where `1` denotes a sunny day and `0` denotes a rainy day. We need to determine if the weather is "Good." The weather is considered "Good" if the number of sunny days is strictly greater than the number of rainy days.

## Intuition & Mathematical Observation
Since there are exactly 7 days in a week:
1. Let $S$ be the count of sunny days (the sum of the input array).
2. Let $R$ be the count of rainy days.
3. We know that $S + R = 7$, which implies $R = 7 - S$.

The condition for "Good" weather is $S > R$. By substituting $R$, we get:
$S > 7 - S$
$2S > 7$
$S > 3.5$

Therefore, the weather is "Good" if there are 4 or more sunny days in the week. We can simply iterate through the input, count the `1`s, and perform the comparison.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of operations (looping exactly 7 times).
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given 7 integers representing days of the week (1 for sunny, 0 for rainy).
 * We need to count the number of sunny days (sum of the array) and compare it 
 * with the number of rainy days (7 - sum of the array).
 * The weather is "Good" if sunny > rainy.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only store a few variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int sunny_days = 0;
        for (int i = 0; i < 7; ++i) {
            int day;
            cin >> day;
            if (day == 1) {
                sunny_days++;
            }
        }

        int rainy_days = 7 - sunny_days;

        // The condition for "Good" weather is strictly greater sunny days than rainy days
        if (sunny_days > rainy_days) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```