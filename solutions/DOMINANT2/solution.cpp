#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An element is dominant if its frequency is strictly greater than the frequency 
 * of any other element in the array.
 * 
 * Approach:
 * 1. Count the frequency of each element in the array.
 * 2. Store these frequencies in a collection (like a vector or map).
 * 3. Sort the frequencies in descending order.
 * 4. If the highest frequency is strictly greater than the second highest frequency,
 *    then a dominant element exists.
 * 5. Special case: If there is only one unique element, it is dominant by default.
 * 
 * Complexity:
 * Time: O(N log N) due to sorting frequencies, where N <= 1000.
 * Space: O(N) to store frequencies.
 */

void solve() {
    int n;
    cin >> n;
    
    // Frequency map to store counts of each element
    // Since 1 <= A_i <= N, a vector of size N+1 is sufficient
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }
    
    // Collect all non-zero frequencies
    vector<int> counts;
    for (int i = 1; i <= n; ++i) {
        if (freq[i] > 0) {
            counts.push_back(freq[i]);
        }
    }
    
    // If there's only one unique element, it's dominant
    if (counts.size() == 1) {
        cout << "YES" << "\n";
        return;
    }
    
    // Sort frequencies in descending order
    sort(counts.rbegin(), counts.rend());
    
    // Check if the highest frequency is strictly greater than the second highest
    if (counts[0] > counts[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}