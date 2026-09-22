#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that Codechef rounds are held only on Wednesday.
 * The input N represents the day of the week:
 * 1: Sunday
 * 2: Monday
 * 3: Tuesday
 * 4: Wednesday
 * 5: Thursday
 * 6: Friday
 * 7: Saturday
 * 
 * Therefore, we need to output "YES" if N == 4, and "NO" otherwise.
 * Constraints: 1 <= N <= 7.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // The problem description implies a single input N, but standard competitive 
    // programming practice often involves test cases. Given the constraints 
    // and format, we read N directly.
    if (!(cin >> n)) return 0;

    if (n == 4) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}