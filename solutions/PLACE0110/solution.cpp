#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Analysis:
 * Each "01" and "10" string has 1 internal transition.
 * Total internal transitions = X + Y.
 * When we connect two strings:
 * - "01"+"10" or "10"+"01" adds 0 transitions.
 * - "01"+"01" or "10"+"10" adds 1 transition.
 * 
 * To minimize, we alternate as much as possible.
 * If X == Y, we have X+Y-1 connections, all 0-cost. Total = X+Y.
 * If X != Y, we have min(X, Y) pairs of (AB) and |X-Y| remaining strings.
 * The number of 1-cost connections is |X-Y| - 1.
 * Total = (X+Y) + (|X-Y| - 1) = 2*max(X, Y) - 1.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;
        if (X == Y) {
            cout << X + Y << "\n";
        } else {
            cout << 2 * max(X, Y) - 1 << "\n";
        }
    }
    return 0;
}