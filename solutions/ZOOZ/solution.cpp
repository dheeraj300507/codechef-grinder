#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a binary string of length N such that the number of "01" subsequences 
 * equals the number of "10" subsequences.
 * 
 * Let the string have 'a' zeros and 'b' ones.
 * If we place a '1' at the start and a '1' at the end, and fill the middle with '0's,
 * the string looks like: 1 00...00 1
 * 
 * For a string starting with 1 and ending with 1, the number of "01" subsequences 
 * is (count of 0s) * (count of 1s after the 0).
 * The number of "10" subsequences is (count of 1s) * (count of 0s after the 1).
 * 
 * A simple construction: 1 followed by (N-2) zeros followed by 1.
 * Example N=4: 1001
 * 01 subsequences: (index 1,3), (index 2,3) -> 2
 * 10 subsequences: (index 0,1), (index 0,2) -> 2
 * This works for any N >= 3.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Construct the string: '1' + (n-2) '0's + '1'
        // This ensures the number of 01 and 10 subsequences are equal.
        string result = "1";
        for (int i = 0; i < n - 2; ++i) {
            result += '0';
        }
        result += '1';
        
        cout << result << "\n";
    }
    
    return 0;
}