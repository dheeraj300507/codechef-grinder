#include <iostream>

/**
 * Problem Analysis:
 * We want to minimize A = C + H subject to 4C + 2H = N.
 * A = C + (N - 4C) / 2 = C + N/2 - 2C = N/2 - C.
 * To minimize A, we must maximize C.
 * The maximum number of cows C is floor(N / 4).
 * 
 * If N % 4 == 0:
 *   Max C = N / 4, H = 0. Total = N / 4.
 * If N % 4 == 2:
 *   Max C = (N - 2) / 4, H = 1. Total = (N - 2) / 4 + 1 = (N + 2) / 4.
 * 
 * Both cases are covered by: (N / 4) + (N % 4) / 2.
 */

using namespace std;

int main() {
    // Optimize I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // Calculate minimum animals:
        // N/4 gives the number of cows (maximizing cows minimizes total animals)
        // (N%4)/2 gives the number of chickens (0 if N%4==0, 1 if N%4==2)
        int min_animals = (n / 4) + ((n % 4) / 2);
        
        cout << min_animals << "\n";
    }
    
    return 0;
}