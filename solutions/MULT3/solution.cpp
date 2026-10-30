#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the nearest multiple of 3 for a given integer N.
 * The distance between N and the nearest multiple of 3 is defined as |N - X|.
 * 
 * For any integer N:
 * 1. If N % 3 == 0, the nearest multiple is N itself.
 * 2. If N % 3 == 1, the multiples are (N-1) and (N+2). 
 *    Distance to (N-1) is 1, distance to (N+2) is 2. So (N-1) is closer.
 * 3. If N % 3 == 2, the multiples are (N-2) and (N+1).
 *    Distance to (N-2) is 2, distance to (N+1) is 1. So (N+1) is closer.
 * 
 * Note: The problem states N is a positive integer (1 <= N <= 10).
 * For N=1: 1 % 3 = 1. Nearest is 1-1 = 0.
 * For N=2: 2 % 3 = 2. Nearest is 2+1 = 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    // The problem description implies a single input N, 
    // but standard competitive programming practice often involves 
    // checking if there are multiple test cases. 
    // Given the constraints and format, we read N.
    if (!(cin >> n)) return 0;

    long long remainder = n % 3;

    if (remainder == 0) {
        cout << n << "\n";
    } else if (remainder == 1) {
        cout << (n - 1) << "\n";
    } else {
        // remainder == 2
        cout << (n + 1) << "\n";
    }

    return 0;
}