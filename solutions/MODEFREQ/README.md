# [Mode of Frequencies (MODEFREQ)](https://www.codechef.com/problems/MODEFREQ)

- **Difficulty Rating**: 1234
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to:
1. Determine the frequency of each distinct number present in the array.
2. Determine the frequency of these frequencies (i.e., how many distinct numbers appear exactly $X$ times).
3. Identify the frequency value $X$ that occurs most frequently. If multiple frequencies have the same maximum count, choose the smallest $X$.

## Intuition & Mathematical Observation
The problem requires a two-step counting process:
1. **First Pass:** Use a frequency map (or an array, given the constraints) to count how many times each number appears in the input array.
2. **Second Pass:** Create a second frequency map to count how many numbers share the same frequency. For example, if the number `5` appears 3 times and the number `7` appears 3 times, the frequency `3` has an occurrence count of `2`.
3. **Tie-breaking:** Since we need the smallest frequency in case of a tie, iterating through a sorted data structure (like `std::map` in C++) or a sorted array allows us to naturally handle the tie-breaking condition. By only updating the result when `occurrences > max_occurrences`, we ensure that if a later frequency has the same count, we ignore it, effectively keeping the smallest frequency.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation. Using `std::map` results in $O(N \log N)$ due to tree insertions. Given $N \le 10000$, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the frequency maps in the worst case (where all elements are distinct).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Calculate the frequency of each distinct number in A.
 * 2. Calculate the frequency of these frequencies.
 * 3. Find the frequency value that appears the most times.
 * 4. If there's a tie, pick the smallest frequency value.
 */

void solve() {
    int N;
    cin >> N;
    
    // Map to store frequency of each number
    map<int, int> counts;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        counts[val]++;
    }
    
    // Map to store how many numbers have a specific frequency
    map<int, int> freq_of_freq;
    for (auto const& [val, count] : counts) {
        freq_of_freq[count]++;
    }
    
    int max_occurrences = 0;
    int result_freq = -1;
    
    // Find the frequency that appears the most times.
    // Iterating through the map (which is sorted by key) ensures 
    // that we encounter smaller frequencies first.
    for (auto const& [freq, occurrences] : freq_of_freq) {
        if (occurrences > max_occurrences) {
            max_occurrences = occurrences;
            result_freq = freq;
        }
    }
    
    cout << result_freq << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```