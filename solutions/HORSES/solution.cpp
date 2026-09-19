#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N horses with skill levels S[i]. We need to find the minimum 
 * difference between the skill levels of any two horses.
 * 
 * Approach:
 * 1. If we sort the array of skill levels, the minimum difference between any 
 *    two horses must occur between adjacent elements in the sorted array.
 * 2. Sorting takes O(N log N) time.
 * 3. After sorting, we iterate through the array once to find the minimum 
 *    difference between adjacent elements, which takes O(N) time.
 * 4. Total time complexity per test case: O(N log N).
 * 5. Given N <= 5000 and T <= 10, this approach is well within the 1.5s time limit.
 * 6. Skill values can be up to 10^9, so the difference fits in a standard 
 *    integer, but using long long is safer for general practice.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    // Sort the skill levels to bring close values together
    sort(s.begin(), s.end());
    
    // Initialize min_diff with a large value
    long long min_diff = LLONG_MAX;
    
    // Compare adjacent elements
    for (int i = 0; i < n - 1; ++i) {
        long long diff = s[i + 1] - s[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    cout << min_diff << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}