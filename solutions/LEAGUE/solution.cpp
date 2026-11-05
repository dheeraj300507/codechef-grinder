#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In a round-robin tournament with N teams:
 * - The winner (Team 1) plays N-1 games. To maximize their points, they win all N-1 games.
 *   Points for Team 1 = 3 * (N - 1).
 * - To maximize the difference, we need to minimize the points of the second-placed team.
 * - Team 1 beats everyone. There are N-1 other teams.
 * - Among these N-1 teams, they play each other in a round-robin tournament of (N-1) teams.
 * - The total number of games played among these N-1 teams is (N-1)*(N-2)/2.
 * - Each game results in 3 points distributed among these N-1 teams.
 * - To minimize the maximum points among these N-1 teams, we want the points to be 
 *   distributed as evenly as possible.
 * - The total points available for these N-1 teams is 3 * [(N-1)*(N-2)/2].
 * - The average points per team among these N-1 teams is:
 *   [3 * (N-1)*(N-2)/2] / (N-1) = 3 * (N-2) / 2.
 * - Since the second-placed team must have at least the average points, the minimum 
 *   possible points for the second-placed team is floor(3 * (N-2) / 2).
 * - Difference = 3*(N-1) - floor(3*(N-2)/2).
 * - If N is odd, N-2 is odd, so 3*(N-2) is odd. floor(3*(N-2)/2) = (3N - 6 - 3) / 2 = (3N - 9) / 2.
 *   Diff = 3N - 3 - (3N - 9)/2 = (6N - 6 - 3N + 9) / 2 = (3N + 3) / 2.
 * - If N is even, N-2 is even, so 3*(N-2) is even. floor(3*(N-2)/2) = 3*(N-2)/2.
 *   Diff = 3N - 3 - (3N - 6)/2 = (6N - 6 - 3N + 6) / 2 = 3N / 2.
 * 
 * Simplified:
 * For N=2: 3(2)/2 = 3.
 * For N=3: (3(3)+3)/2 = 6/2 = 6? Wait, sample says 3.
 * Let's re-check:
 * N=3: Winner 6 pts. Remaining 2 teams play 1 game. One gets 3, one gets 0. Max is 3. Diff 6-3=3.
 * N=4: Winner 9 pts. Remaining 3 teams play 3 games. Total 9 pts. Evenly: 3, 3, 3. Diff 9-3=6.
 * N=9: Winner 24 pts. Remaining 8 teams play 28 games. Total 84 pts. Avg 84/8 = 10.5. 
 *      Second place gets 12. Diff 24-12=12.
 * 
 * Pattern:
 * N=2 -> 3
 * N=3 -> 3
 * N=4 -> 6
 * N=9 -> 12
 * The formula is: 3 * (N / 2)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        // Based on the pattern:
        // N=2: 3*(2/2) = 3
        // N=3: 3*(3/2) = 3
        // N=4: 3*(4/2) = 6
        // N=9: 3*(9/2) = 12
        cout << 3 * (n / 2) << "\n";
    }
    return 0;
}