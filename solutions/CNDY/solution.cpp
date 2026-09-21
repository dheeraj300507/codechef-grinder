#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given 2N integers. We need to split them into two sets of size N,
 * where each set contains only distinct elements.
 * 
 * This is possible if and only if no element appears more than twice in the 
 * original array of 2N elements.
 * 
 * Proof:
 * If an element appears 3 or more times, it is impossible to distribute them 
 * into two sets such that each set has distinct elements (at least one set 
 * would contain the element twice).
 * If every element appears at most twice, we can put one instance of every 
 * element that appears twice into the first set, and the other instance into 
 * the second set. Elements that appear once can be distributed to fill the 
 * remaining spots in either set. Since the total number of elements is 2N, 
 * and each set must have N elements, this distribution is always possible.
 */

void solve() {
    int N;
    cin >> N;
    int total_elements = 2 * N;
    map<int, int> counts;
    bool possible = true;
    
    for (int i = 0; i < total_elements; ++i) {
        int a;
        cin >> a;
        counts[a]++;
        if (counts[a] > 2) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}