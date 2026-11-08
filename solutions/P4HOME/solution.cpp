#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at x.
 * Friends are at [x - y, x + y] excluding x.
 * Chef can travel to [x - z, x + z].
 * 
 * The range of friends Chef can visit is the intersection of:
 * [x - y, x + y] AND [x - z, x + z]
 * This intersection is [x - min(y, z), x + min(y, z)].
 * 
 * Within this intersection, Chef can visit all integer points except x.
 * The number of integers in [x - k, x + k] is (x + k) - (x - k) + 1 = 2k + 1.
 * Since we must exclude x, the number of friends is (2k + 1) - 1 = 2k,
 * where k = min(y, z).
 * 
 * If k = 0, the range is [x, x], which contains only x. Excluding x, there are 0 friends.
 * The formula 2 * min(y, z) holds true for all non-negative y, z.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // The number of friends is 2 * min(y, z)
        // because the intersection of [x-y, x+y] and [x-z, x+z]
        // is [x - min(y, z), x + min(y, z)].
        // The number of integers in this range is 2 * min(y, z) + 1.
        // Excluding the position x itself, we have 2 * min(y, z) friends.
        
        long long k = min(y, z);
        long long ans = 2 * k;
        
        cout << ans << "\n";
    }

    return 0;
}