#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: WEIGHTLIFT
 * The goal is to find the maximum of two attempts for each of the three rounds
 * and sum these maximums to get the total score.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a1, a2, b1, b2, c1, c2;
    
    // Reading the 6 space-separated integers
    if (cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2) {
        // Calculate the best score for each round
        long long round1 = max(a1, a2);
        long long round2 = max(b1, b2);
        long long round3 = max(c1, c2);
        
        // Calculate total score
        long long total_score = round1 + round2 + round3;
        
        // Output the result
        cout << total_score << "\n";
    }

    return 0;
}