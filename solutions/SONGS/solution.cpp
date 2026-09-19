#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each song has duration X.
 * The playlist consists of 3 songs: A, B, C.
 * Total duration of one full cycle (A -> B -> C) is 3 * X.
 * 
 * To find how many times song C is completed:
 * 1. Calculate the total number of full songs played: total_songs = N / X.
 * 2. In every full cycle of 3 songs, song C appears exactly once.
 * 3. The number of full cycles completed is (total_songs / 3).
 * 4. This gives the number of times C is completed in full cycles.
 * 5. If there are remaining songs after full cycles (total_songs % 3), 
 *    we check if the remainder is 3 (which is impossible) or if the 
 *    sequence of songs played includes C.
 *    The sequence is A, B, C, A, B, C...
 *    - If total_songs % 3 == 0: C is completed (total_songs / 3) times.
 *    - If total_songs % 3 == 1: C is completed (total_songs / 3) times.
 *    - If total_songs % 3 == 2: C is completed (total_songs / 3) times.
 *    Wait, let's re-verify:
 *    If total_songs = 1 (A), C is 0 times.
 *    If total_songs = 2 (A, B), C is 0 times.
 *    If total_songs = 3 (A, B, C), C is 1 time.
 *    If total_songs = 4 (A, B, C, A), C is 1 time.
 *    If total_songs = 5 (A, B, C, A, B), C is 1 time.
 *    If total_songs = 6 (A, B, C, A, B, C), C is 2 times.
 *    
 *    The formula is simply: total_songs / 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // Total number of songs completed
        long long total_songs = n / x;
        
        // Each cycle of 3 songs contains exactly one C
        long long count_c = total_songs / 3;
        
        cout << count_c << "\n";
    }
    
    return 0;
}