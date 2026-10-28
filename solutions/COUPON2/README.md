# [Chef and Coupon (COUPON2)](https://www.codechef.com/problems/COUPON2)

- **Difficulty Rating**: 1222
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef orders food for two days. Each day, he orders three items. There is a delivery charge $D$ for every order unless the order total is at least 150. Chef can also purchase a coupon for price $C$, which makes the delivery charge free for both days, regardless of the order totals. We need to determine if buying the coupon is strictly cheaper than not buying it.

## Intuition & Mathematical Observation
To decide whether to buy the coupon, we compare two scenarios:

1.  **Without Coupon**: Chef pays for all items plus the delivery charge $D$ for both days.
    *   `Cost_Without = (SumA + D) + (SumB + D)`
2.  **With Coupon**: Chef pays for all items, the coupon price $C$, and a delivery charge only for the days where the order total is less than 150.
    *   `Cost_With = SumA + SumB + C + (delivery_charge_day1) + (delivery_charge_day2)`
    *   Where `delivery_charge` is $D$ if the sum is $< 150$, and $0$ otherwise.

The coupon is worth buying if and only if `Cost_With < Cost_Without`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the sums and costs.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Cost without coupon: (SumA + D) + (SumB + D) = SumA + SumB + 2*D
 * - Cost with coupon: SumA + SumB + C + (delivery_charge_day1) + (delivery_charge_day2)
 *   - delivery_charge_day1 = (SumA >= 150) ? 0 : D
 *   - delivery_charge_day2 = (SumB >= 150) ? 0 : D
 * 
 * Chef buys the coupon if: Cost_with_coupon < Cost_without_coupon
 */

void solve() {
    int D, C;
    if (!(cin >> D >> C)) return;
    
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    int sumA = A1 + A2 + A3;
    
    int B1, B2, B3;
    cin >> B1 >> B2 >> B3;
    int sumB = B1 + B2 + B3;
    
    // Cost without coupon: pay delivery fee on both days
    int costWithout = sumA + sumB + 2 * D;
    
    // Cost with coupon: pay coupon price + delivery fee only if sum < 150
    int deliveryDay1 = (sumA >= 150) ? 0 : D;
    int deliveryDay2 = (sumB >= 150) ? 0 : D;
    int costWith = sumA + sumB + C + deliveryDay1 + deliveryDay2;
    
    if (costWith < costWithout) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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