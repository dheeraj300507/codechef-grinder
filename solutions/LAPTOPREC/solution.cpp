#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N recommendations for 10 possible laptops (1 to 10).
 * We need to count the frequency of each laptop ID and find which one appears most often.
 * If there is a tie for the maximum frequency, output "CONFUSED".
 * 
 * Constraints:
 * T <= 200, N <= 1000, A_i in [1, 10].
 * Since the range of laptop IDs is very small (1-10), we can use a frequency array
 * of size 11 to store the counts.
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1) (constant space for the frequency array)
 */

void solve() {
    int n;
    cin >> n;
    
    // Frequency array for laptops 1 to 10
    int freq[11] = {0};
    
    for (int i = 0; i < n; ++i) {
        int laptop_id;
        cin >> laptop_id;
        if (laptop_id >= 1 && laptop_id <= 10) {
            freq[laptop_id]++;
        }
    }
    
    int max_freq = -1;
    int best_laptop = -1;
    bool confused = false;
    
    for (int i = 1; i <= 10; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            best_laptop = i;
            confused = false;
        } else if (freq[i] == max_freq && max_freq > 0) {
            confused = true;
        }
    }
    
    if (confused) {
        cout << "CONFUSED" << "\n";
    } else {
        cout << best_laptop << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}