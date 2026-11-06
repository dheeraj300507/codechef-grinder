#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The robot starts at (0, 0).
 * Let the final position after N moves be (X, Y).
 * If we change a move 'U' to 'D', the Y-coordinate changes by -2 (from +1 to -1).
 * If we change a move 'D' to 'U', the Y-coordinate changes by +2 (from -1 to +1).
 * If we change a move 'L' to 'R', the X-coordinate changes by +2 (from -1 to +1).
 * If we change a move 'R' to 'L', the X-coordinate changes by -2 (from +1 to -1).
 * 
 * We want the final position to be (0, 0).
 * Let the current final position be (X, Y).
 * After changing one move, the new position (X', Y') must be (0, 0).
 * 
 * Case 1: Changing 'U' to 'D' (Y becomes Y-2):
 * We need Y-2 = 0 => Y = 2, and X = 0.
 * Case 2: Changing 'D' to 'U' (Y becomes Y+2):
 * We need Y+2 = 0 => Y = -2, and X = 0.
 * Case 3: Changing 'L' to 'R' (X becomes X+2):
 * We need X+2 = 0 => X = -2, and Y = 0.
 * Case 4: Changing 'R' to 'L' (X becomes X-2):
 * We need X-2 = 0 => X = 2, and Y = 0.
 * 
 * So, we check if there exists at least one move of the required type 
 * that allows us to reach (0, 0) by flipping it.
 */

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'U') y++;
        else if (c == 'D') y--;
        else if (c == 'L') x--;
        else if (c == 'R') x++;
    }

    bool possible = false;
    for (char c : s) {
        int nx = x, ny = y;
        if (c == 'U') {
            ny -= 2;
        } else if (c == 'D') {
            ny += 2;
        } else if (c == 'L') {
            nx += 2;
        } else if (c == 'R') {
            nx -= 2;
        }
        
        if (nx == 0 && ny == 0) {
            possible = true;
            break;
        }
    }

    if (possible) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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