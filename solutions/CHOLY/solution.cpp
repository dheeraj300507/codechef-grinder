#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each team plays 4 games in total.
 * Current state: X wins, Y draws, Z losses.
 * Total games played = X + Y + Z.
 * Remaining games = 4 - (X + Y + Z).
 * 
 * Current points for our team: P_us = X * 1.0 + Y * 0.5
 * Current points for opponent: P_opp = Z * 1.0 + Y * 0.5
 * 
 * To maximize our chances of winning, we assume we win all remaining games.
 * If we win all remaining games, our final points will be:
 * P_us_final = P_us + (4 - (X + Y + Z))
 * P_opp_final = P_opp
 * 
 * We win the round if P_us_final > P_opp_final.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Calculate current points (using double to handle 0.5)
    double p_us = (double)X + (double)Y * 0.5;
    double p_opp = (double)Z + (double)Y * 0.5;

    // Number of games remaining
    int remaining = 4 - (X + Y + Z);

    // If we win all remaining games, our score increases by 'remaining'
    double p_us_final = p_us + (double)remaining;
    double p_opp_final = p_opp;

    // Check if strictly greater
    if (p_us_final > p_opp_final) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}