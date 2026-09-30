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
 * 
 * Constraints:
 * X: 31 to 40
 * A: 101 to 120
 * B: 1 to 5
 * Calculations will easily fit in a standard integer, but using long long is safe practice.
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