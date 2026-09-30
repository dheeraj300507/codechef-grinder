# [Solubility (SOLBLTY)](https://www.codechef.com/problems/SOLBLTY)

- **Difficulty Rating**: 922
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the initial temperature $X$ of water and the solubility $A$ (in grams per 100mL) at that temperature, we need to find the maximum amount of sugar that can be dissolved in 1 liter (1000mL) of water when heated to 100 degrees Celsius. The solubility increases by $B$ grams per 100mL for every degree increase in temperature.

## Intuition & Mathematical Observation
1. **Temperature Difference**: The temperature increases from $X$ to 100 degrees. The total increase is $(100 - X)$ degrees.
2. **Solubility at 100°C**: Since the solubility increases by $B$ for every degree, the solubility at 100°C per 100mL is:
   $$\text{Solubility}_{100} = A + (100 - X) \times B$$
3. **Scaling to 1 Liter**: The problem asks for the total sugar in 1 liter of water. Since 1 liter = 1000mL, and our solubility is defined per 100mL, we have 10 units of 100mL.
   $$\text{Total Sugar} = \text{Solubility}_{100} \times 10$$
4. **Constraints**: With $X \in [31, 40]$, $A \in [101, 120]$, and $B \in [1, 5]$, the resulting values are well within the range of standard integer types, making the calculation straightforward.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial temperature: X
 * Solubility at X: A g/100mL
 * Increase in solubility per degree: B g/100mL
 * Target temperature: 100 degrees
 * 
 * Solubility at 100 degrees = A + (100 - X) * B (in g/100mL)
 * Since we have 1 liter of water (1000 mL), we have 10 units of 100mL.
 * Total sugar = (Solubility at 100 degrees) * 10
 * Total sugar = (A + (100 - X) * B) * 10
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;
        
        // Calculate solubility at 100 degrees per 100mL
        long long solubility_at_100 = a + (100 - x) * b;
        
        // Calculate total sugar for 1 liter (1000mL = 10 * 100mL)
        long long total_sugar = solubility_at_100 * 10;
        
        cout << total_sugar << "\n";
    }
    
    return 0;
}
```