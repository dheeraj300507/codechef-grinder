#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef eats X + (R / 30) sticks in total.
 * Let S = X + (R / 30).
 * Each plate contains Y sticks.
 * To eat S sticks, Chef must order at least ceil(S / Y) plates.
 * Since he doesn't order a new plate until the previous one is finished,
 * the number of plates is exactly ceil(S / Y).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y, R;
        cin >> X >> Y >> R;

        // Calculate extra sticks eaten
        long long extra_sticks = R / 30;
        
        // Total sticks eaten
        long long total_sticks = X + extra_sticks;
        
        // Number of plates needed to cover total_sticks
        // Using integer division for ceiling: (a + b - 1) / b
        long long plates = (total_sticks + Y - 1) / Y;
        
        cout << plates << "\n";
    }

    return 0;
}