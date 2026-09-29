#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Reach 5 Star
 * Logic:
 * Chef's current rating is X.
 * After the contest, the rating becomes X + Y.
 * Chef is 5-star if (X + Y) >= 2000.
 * 
 * Constraints:
 * 0 <= X < 2000
 * -2000 <= Y < 2000
 * The result X + Y will be in the range [-2000, 4000].
 * Standard 'int' is sufficient as it handles values up to 2*10^9.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice often involves handling 
    // multiple test cases if specified. Given the prompt structure, 
    // we read X and Y directly.
    
    int X, Y;
    if (!(cin >> X >> Y)) return 0;

    // Calculate new rating
    int new_rating = X + Y;

    // Check condition
    if (new_rating >= 2000) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}