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
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
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