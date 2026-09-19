# [Bath in Winters (BATH)](https://www.codechef.com/problems/BATH)

- **Difficulty Rating**: 643
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a geyser with a total water capacity of $X$ litres. Each person requires 2 buckets of water to take a bath, and each bucket has a capacity of $Y$ litres. We need to determine the maximum number of people who can take a bath given the total available water $X$.

## Intuition & Mathematical Observation
1. **Water Requirement**: Each person needs 2 buckets. Since each bucket holds $Y$ litres, the total water required for one person is $2 \times Y$ litres.
2. **Calculation**: To find out how many people can be accommodated, we divide the total available water ($X$) by the water required per person ($2 \times Y$).
3. **Integer Division**: Since we cannot have a fraction of a person, we use integer division (which naturally performs the `floor` operation) to find the maximum number of people:
   $$\text{People} = \lfloor \frac{X}{2 \times Y} \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Geyser capacity: X litres
 * - Bucket capacity: Y litres
 * - Water required per person: 2 * Y litres
 * - Number of people = floor(X / (2 * Y))
 * 
 * Constraints:
 * - 1 <= T <= 1000
 * - 1 <= X, Y <= 100
 * 
 * Since X and Y are small, standard integer division will work perfectly.
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
        long long x, y;
        cin >> x >> y;
        
        // Each person needs 2 * y litres of water.
        // The number of people is the total capacity divided by the requirement per person.
        long long water_per_person = 2 * y;
        
        // Using integer division to get the floor value
        long long max_people = x / water_per_person;
        
        cout << max_people << "\n";
    }
    
    return 0;
}
```