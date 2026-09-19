#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N be the number of mangoes.
 * The total weight is (N * X) + Y.
 * The bridge can withstand weight Z.
 * We need (N * X) + Y <= Z.
 * N * X <= Z - Y
 * N <= (Z - Y) / X
 * Since we want the maximum number of mangoes, N = floor((Z - Y) / X).
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= X <= Y <= Z <= 100
 * Since the values are small, standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        // The weight available for mangoes is Z - Y.
        // If Z - Y < 0, it's impossible (though constraints say Y <= Z).
        // The number of mangoes is the integer division of available weight by mango weight.
        int available_weight = z - y;
        int max_mangoes = available_weight / x;
        
        cout << max_mangoes << "\n";
    }
    
    return 0;
}