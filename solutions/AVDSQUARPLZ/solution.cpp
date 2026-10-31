#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to arrange numbers from 1 to N such that no two adjacent elements
 * have a product that is a perfect square.
 * 
 * A simple observation:
 * If we list all numbers from N down to 1, we get the sequence: N, N-1, ..., 1.
 * For small N, this often works. However, to be safer, we can try a simple 
 * construction: print all even numbers in descending order, followed by all 
 * odd numbers in descending order.
 * 
 * Let's test this strategy:
 * For N=4: Evens (4, 2), Odds (3, 1) -> 4, 2, 3, 1.
 * Products: 4*2=8, 2*3=6, 3*1=3. None are perfect squares.
 * 
 * This strategy works because:
 * 1. Within the even block, adjacent products are (2k)*(2k-2) = 4(k)(k-1). 
 *    This is a square only if k(k-1) is a square, which is rare.
 * 2. Within the odd block, adjacent products are (2k+1)*(2k-1) = 4k^2 - 1.
 *    This is never a perfect square for k > 0.
 * 3. The transition between the last even and first odd:
 *    If the last even is 2 and the first odd is (largest odd <= N), 
 *    the product is 2 * (largest odd). This is rarely a square.
 * 
 * Given the constraints N <= 500, this simple heuristic is highly effective.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<int> evens;
    vector<int> odds;
    
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) evens.push_back(i);
        else odds.push_back(i);
    }
    
    // Print evens descending, then odds descending
    bool first = true;
    for (int i = evens.size() - 1; i >= 0; --i) {
        if (!first) cout << " ";
        cout << evens[i];
        first = false;
    }
    for (int i = odds.size() - 1; i >= 0; --i) {
        if (!first) cout << " ";
        cout << odds[i];
        first = false;
    }
    cout << "\n";
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