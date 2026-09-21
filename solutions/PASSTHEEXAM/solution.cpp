#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Pass the Exam
 * Logic:
 * Chef passes if:
 * 1. Total score (A + B + C) >= 100
 * 2. Each section score >= 10 (A >= 10, B >= 10, C >= 10)
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Check conditions:
        // 1. Total score >= 100
        // 2. Each section >= 10
        if ((a + b + c >= 100) && (a >= 10) && (b >= 10) && (c >= 10)) {
            cout << "PASS" << "\n";
        } else {
            cout << "FAIL" << "\n";
        }
    }
    
    return 0;
}