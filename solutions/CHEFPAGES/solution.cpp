#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A = 0: User has never submitted on the practice page. Output: https://www.codechef.com/practice
 * A = 1, B = 0: User has submitted on practice, but not in a contest. Output: https://www.codechef.com/contests
 * A = 1, B = 1: User has submitted on practice and in a contest. Output: https://discuss.codechef.com
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    // The problem description implies a single input line, but standard competitive 
    // programming practice often involves a single test case unless specified otherwise.
    // Given the constraints and format, we read A and B.
    if (cin >> A >> B) {
        if (A == 0) {
            cout << "https://www.codechef.com/practice" << "\n";
        } else if (A == 1 && B == 0) {
            cout << "https://www.codechef.com/contests" << "\n";
        } else if (A == 1 && B == 1) {
            cout << "https://discuss.codechef.com" << "\n";
        }
    }

    return 0;
}