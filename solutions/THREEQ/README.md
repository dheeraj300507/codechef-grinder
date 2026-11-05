# [The Old Saint And Three Questions (THREEQ)](https://www.codechef.com/problems/THREEQ)

- **Difficulty Rating**: 954
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a hero's responses to three questions match the correct answers. We are given two sets of three integers (each being either 0 or 1). We need to output "Pass" if the hero's responses are identical in count to the correct answers, and "Fail" otherwise. Specifically, the hero passes if the number of '1's in their response matches the number of '1's in the correct answer (which implicitly means the number of '0's will also match).

## Intuition & Mathematical Observation
Since there are exactly three questions, the total number of '1's (representing "Yes") and '0's (representing "No") determines the outcome. 

If we sum the three integers provided for the correct answers ($A_1 + A_2 + A_3$) and compare that to the sum of the hero's responses ($B_1 + B_2 + B_3$), we can determine if the sets are equivalent in terms of the number of "Yes" responses. Because the total number of questions is fixed at 3, if the number of "Yes" responses is equal, the number of "No" responses must also be equal. Therefore, a simple comparison of the sums is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks whether the count of '1's (Yes) and '0's (No) in the hero's 
 * responses matches the count of '1's and '0's in the correct answers.
 * Since there are only 3 questions, we can simply count the number of 1s 
 * in both sets. If the count of 1s is the same, the count of 0s must also 
 * be the same (since total questions = 3).
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a1, a2, a3;
        int b1, b2, b3;

        cin >> a1 >> a2 >> a3;
        cin >> b1 >> b2 >> b3;

        // Calculate the sum of 1s for both sets
        int sum_a = a1 + a2 + a3;
        int sum_b = b1 + b2 + b3;

        // If the number of 'Yes' (1s) matches, the number of 'No' (0s) 
        // must also match because the total number of questions is fixed at 3.
        if (sum_a == sum_b) {
            cout << "Pass" << "\n";
        } else {
            cout << "Fail" << "\n";
        }
    }

    return 0;
}
```