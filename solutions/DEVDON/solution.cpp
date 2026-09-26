#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Devouring Donuts
 * The problem asks to calculate the total calories consumed by multiplying 
 * the number of donuts (X) by the calories per donut (Y).
 * 
 * Constraints:
 * 1 <= X <= 10
 * 200 <= Y <= 300
 * 
 * The maximum possible result is 10 * 300 = 3000, which fits easily 
 * within a standard 32-bit integer. However, using long long is 
 * good practice for competitive programming to prevent overflow in 
 * similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description does not explicitly state multiple test cases,
    // but the instructions mention handling them if requested. 
    // Based on the input format "The only line of input contains...", 
    // we read X and Y once.
    
    long long X, Y;
    if (cin >> X >> Y) {
        long long total_calories = X * Y;
        cout << total_calories << "\n";
    }

    return 0;
}