#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each round of Surya Namaskar consists of 12 yoga poses.
 * Given N total poses, the number of complete rounds is the integer division of N by 12.
 * 
 * Constraints:
 * 1 <= N <= 100
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input N per run, 
    // but standard competitive programming practice often involves 
    // handling test cases if specified. Given the constraints and format,
    // we read N and output the result of integer division.
    
    int N;
    if (cin >> N) {
        int rounds = N / 12;
        cout << rounds << "\n";
    }

    return 0;
}