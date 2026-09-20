#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Self Defence Training
 * The condition for eligibility is age A_i such that 10 <= A_i <= 60.
 * We iterate through each age and count how many satisfy this condition.
 * Time Complexity: O(T * N)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            // Check if age is within the inclusive range [10, 60]
            if (age >= 10 && age <= 60) {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}