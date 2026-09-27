#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The goal is to have 5 gold, 5 silver, and 5 bronze medals.
 * Given current medals G, S, B, the number of additional medals needed is:
 * (5 - G) + (5 - S) + (5 - B)
 * Since 1 <= G, S, B <= 5, the result will always be non-negative.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, S, B;
    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves reading until EOF 
    // or handling a specific number of test cases. Given the constraints and format:
    if (cin >> G >> S >> B) {
        int needed_gold = 5 - G;
        int needed_silver = 5 - S;
        int needed_bronze = 5 - B;
        
        int total_needed = needed_gold + needed_silver + needed_bronze;
        
        cout << total_needed << "\n";
    }

    return 0;
}