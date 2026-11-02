#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X ones and Y twos. Total elements N = X + Y.
 * We need to form N/3 groups of 3 elements each.
 * Each group contributes max(A_i, A_j, A_k) to the score.
 * 
 * To maximize the score, we want as many groups as possible to have a max of 2.
 * A group has a max of 2 if it contains at least one '2'.
 * A group has a max of 1 only if it contains three '1's.
 * 
 * Strategy:
 * 1. We have Y twos. Each '2' can "cover" a group to make its max 2.
 * 2. We want to use our Y twos to make as many groups of 2 as possible.
 * 3. Each group needs 3 elements. If we use one '2' in a group, we need 2 other elements.
 *    To save '1's for other potential groups, we should use the remaining '2's 
 *    to fill these spots if available.
 * 4. Effectively, we can form a group with max 2 by using one '2' and any two other elements.
 *    We have Y twos. We can form at most Y groups that result in a score of 2, 
 *    provided we have enough elements to fill the remaining 2 spots in each of those groups.
 * 5. Total groups = (X + Y) / 3.
 *    Number of groups with max 2 = min(Y, (X + Y) / 3).
 *    Remaining groups will have max 1.
 * 6. Score = (Number of groups with max 2) * 2 + (Number of groups with max 1) * 1.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    long long total_elements = X + Y;
    long long total_groups = total_elements / 3;
    
    // We want to maximize the number of groups that contain at least one '2'.
    // Each '2' can be the 'max' for one group.
    // Since we have Y twos, we can form at most Y groups with max 2.
    // Also, we are limited by the total number of groups available.
    long long groups_with_2 = min(Y, total_groups);
    long long groups_with_1 = total_groups - groups_with_2;
    
    long long score = (groups_with_2 * 2) + (groups_with_1 * 1);
    cout << score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}