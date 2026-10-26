#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The surface area of a rectangular box with dimensions H, L, and W is given by:
 * Surface Area = 2 * (H*L + L*W + W*H)
 * 
 * Chef has a total of 1000 square centimeters of wrapping paper.
 * To find the maximum number of complete gifts, we divide the total area (1000)
 * by the surface area of one gift and take the floor of the result.
 * 
 * Constraints:
 * T <= 1000
 * 1 <= H, L, W <= 10
 * The surface area will be at most 2 * (10*10 + 10*10 + 10*10) = 600.
 * The minimum surface area will be 2 * (1*1 + 1*1 + 1*1) = 6.
 * Integer division is sufficient as the result will fit in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long h, l, w;
        cin >> h >> l >> w;

        // Calculate surface area of one gift
        // Formula: 2 * (HL + LW + WH)
        long long surface_area = 2 * (h * l + l * w + w * h);

        // Total paper available is 1000
        long long total_paper = 1000;

        // Calculate maximum number of gifts
        long long max_gifts = total_paper / surface_area;

        cout << max_gifts << "\n";
    }

    return 0;
}