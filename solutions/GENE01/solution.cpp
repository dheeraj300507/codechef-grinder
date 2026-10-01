#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that brown (R) is the most common, blue (B) is next, 
 * and green (G) is the rarest.
 * The child's eye color is the most common of the two parents' eye colors.
 * 
 * Hierarchy: R > B > G
 * If we assign values: R = 3, B = 2, G = 1
 * The child's color will be the maximum of the two parents' values.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char p1, p2;
    if (!(cin >> p1 >> p2)) return 0;

    // Map characters to priority values
    auto get_val = [](char c) {
        if (c == 'R') return 3;
        if (c == 'B') return 2;
        return 1; // G
    };

    int v1 = get_val(p1);
    int v2 = get_val(p2);

    int result_val = max(v1, v2);

    if (result_val == 3) {
        cout << "R" << "\n";
    } else if (result_val == 2) {
        cout << "B" << "\n";
    } else {
        cout << "G" << "\n";
    }

    return 0;
}