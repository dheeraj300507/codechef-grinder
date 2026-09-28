# [Chef and SnackDown (SNCKYEAR)](https://www.codechef.com/problems/SNCKYEAR)

- **Difficulty Rating**: 895
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine whether the SnackDown programming contest was hosted in a given year $N$. We are provided with a specific list of years in which the contest took place: 2010, 2015, 2016, 2017, and 2019. For any input year $N$ (where $2010 \le N \le 2019$), we must output "HOSTED" if the year is in the list, and "NOT HOSTED" otherwise.

## Intuition & Mathematical Observation
Since the range of possible years is very small ($2010$ to $2019$), we do not need complex data structures or algorithms. The problem can be solved by simply checking if the input integer $N$ matches any of the five known years. 

Using a conditional `if` statement or a `switch` case is the most efficient approach. Alternatively, one could store the years in a `std::set` or an array and check for existence, but a direct comparison is faster and uses less memory.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a constant number of comparisons regardless of the input value, the time complexity is constant.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input and the test case count, requiring no extra space that scales with input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and SnackDown
 * The years SnackDown was hosted are: 2010, 2015, 2016, 2017, 2019.
 * Given the constraints (2010 <= N <= 2019), a simple conditional check is efficient.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        // Check if the year is one of the hosted years
        if (n == 2010 || n == 2015 || n == 2016 || n == 2017 || n == 2019) {
            cout << "HOSTED" << "\n";
        } else {
            cout << "NOT HOSTED" << "\n";
        }
    }

    return 0;
}
```