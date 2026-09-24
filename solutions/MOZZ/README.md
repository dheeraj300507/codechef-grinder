# [Endless Appetizers (MOZZ)](https://www.codechef.com/problems/MOZZ)

- **Difficulty Rating**: 752
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef starts by eating $X$ mozzarella sticks. Additionally, for every $30$ rupees he spends on extra sticks, he gets one extra stick. Each plate contains $Y$ sticks. We need to determine the minimum number of plates Chef must order to satisfy his hunger, given that he eats $X$ initial sticks plus the extra sticks earned from spending $R$ rupees.

## Intuition & Mathematical Observation
1. **Calculate Total Sticks**: 
   - Chef eats $X$ sticks initially.
   - With $R$ rupees, he earns $\lfloor R / 30 \rfloor$ extra sticks.
   - Total sticks $S = X + (R / 30)$.
2. **Calculate Plates**:
   - Each plate contains $Y$ sticks.
   - To find the number of plates required to cover $S$ sticks, we need to perform a ceiling division: $\lceil S / Y \rceil$.
   - In integer arithmetic, $\lceil a / b \rceil$ can be calculated efficiently using the formula `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef eats X + (R / 30) sticks in total.
 * Let S = X + (R / 30).
 * Each plate contains Y sticks.
 * To eat S sticks, Chef must order at least ceil(S / Y) plates.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y, R;
        cin >> X >> Y >> R;

        // Calculate extra sticks eaten
        long long extra_sticks = R / 30;
        
        // Total sticks eaten
        long long total_sticks = X + extra_sticks;
        
        // Number of plates needed to cover total_sticks
        // Using integer division for ceiling: (a + b - 1) / b
        long long plates = (total_sticks + Y - 1) / Y;
        
        cout << plates << "\n";
    }

    return 0;
}
```