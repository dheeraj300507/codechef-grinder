#include <iostream>

/**
 * Problem Analysis:
 * A "double string" of length L = 2k requires the first half to equal the second half.
 * This implies every character used must appear an even number of times.
 * In a palindrome of length N:
 * - If N is even, all characters appear an even number of times. We can use all N.
 * - If N is odd, exactly one character appears an odd number of times. We must 
 *   remove at least one character to make all counts even, resulting in N-1.
 * 
 * The formula (N / 2) * 2 correctly computes the largest even integer <= N.
 */

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            cin >> n;
            
            // The maximal length is the largest even number <= N
            // This is equivalent to n - (n % 2)
            cout << (n / 2) * 2 << "\n";
        }
    }
    return 0;
}