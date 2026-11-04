# [Laptop Recommendation (LAPTOPREC)](https://www.codechef.com/problems/LAPTOPREC)

- **Difficulty Rating**: 1104
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a list of $N$ laptop recommendations where each recommendation is an integer between 1 and 10, determine which laptop ID appears most frequently. If there is a unique laptop with the highest frequency, output its ID. If multiple laptops share the same maximum frequency, output "CONFUSED".

## Intuition & Mathematical Observation
Since the range of possible laptop IDs is very small (fixed between 1 and 10), we do not need complex data structures like hash maps. A simple frequency array (or "bucket") of size 11 is sufficient to store the count of each laptop ID.

1. **Counting**: Iterate through the input array and increment the corresponding index in the frequency array for each laptop ID encountered.
2. **Finding the Maximum**: Iterate through the frequency array (from 1 to 10) to track the highest frequency found so far.
3. **Handling Ties**: 
   - If we find a frequency strictly greater than the current `max_freq`, we update the `best_laptop` and reset the `confused` flag to `false`.
   - If we find a frequency equal to the current `max_freq` (and that frequency is greater than 0), it implies a tie, so we set the `confused` flag to `true`.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of recommendations. We iterate through the input once per test case and perform a constant-time scan (size 10) of the frequency array.
- **Space Complexity**: $O(1)$, as we use a fixed-size array of size 11 regardless of the input size $N$.

## Solution Code

```cpp
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
```