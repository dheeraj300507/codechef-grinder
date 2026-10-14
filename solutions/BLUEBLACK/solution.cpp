#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs either:
 * 1. 3 blue pens: Cost = 3 * A
 * 2. 1 blue pen and 1 black pen: Cost = A + B
 * 
 * We need to find the minimum of these two options: min(3 * A, A + B).
 * Constraints: 10 <= A, B <= 50.
 * Since the values are small, standard 'int' is sufficient, but 'long long' 
 * is used for robustness.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice often involves reading until EOF
    // or handling a specific number of test cases. Given the description:
    // "The first and only line contains 2 integers"
    if (cin >> A >> B) {
        long long option1 = 3 * A;
        long long option2 = A + B;
        
        cout << min(option1, option2) << "\n";
    }

    return 0;
}