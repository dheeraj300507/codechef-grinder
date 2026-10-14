#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A cab can hold at most 4 people.
 * Cost for X people in one cab = max(200, 100 * X).
 * 
 * If we put X people in a cab:
 * - If X = 1, cost = max(200, 100) = 200
 * - If X = 2, cost = max(200, 200) = 200
 * - If X = 3, cost = max(200, 300) = 300
 * - If X = 4, cost = max(200, 400) = 400
 * 
 * To minimize cost for N people:
 * We want to pack as many people as possible into cabs such that the cost per person is minimized.
 * - 4 people in one cab: 400 (100 per person)
 * - 3 people in one cab: 300 (100 per person)
 * - 2 people in one cab: 200 (100 per person)
 * - 1 person in one cab: 200 (200 per person)
 * 
 * Strategy:
 * We should prioritize filling cabs with 2, 3, or 4 people to keep the cost at 100 per person.
 * Only if we have a remainder of 1 person, we should pair them with another cab to avoid the 200 cost.
 * Actually, since 2 people cost 200, it is always optimal to group people into sets of 2, 3, or 4.
 * If N is even, we can always group them into pairs of 2 (cost 200 each) or groups of 4 (cost 400 each).
 * If N is odd, we can have one group of 3 and the rest in groups of 2 or 4.
 * Effectively, the cost is simply N * 100, but we must ensure we don't pay less than 200 per cab.
 * Since N >= 1, the minimum cost is ceil(N/2) * 200 is not quite right because 3 people cost 300.
 * 
 * Let's re-evaluate:
 * N=1: 200
 * N=2: 200
 * N=3: 300
 * N=4: 400
 * N=5: 500 (3+2)
 * N=6: 600 (4+2 or 3+3)
 * The pattern is simply N * 100, but with a floor of 200 per cab.
 * Since we can always split N into groups of 2, 3, or 4, the cost is N * 100.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Based on the logic:
        // 1 -> 200
        // 2 -> 200
        // 3 -> 300
        // 4 -> 400
        // 5 -> 500
        // 6 -> 600
        // The formula is max(200, n * 100)
        long long ans = max(200LL, (long long)n * 100);
        cout << ans << "\n";
    }
    return 0;
}