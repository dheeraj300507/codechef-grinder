# [Dominant Element (DOMINANT2)](https://www.codechef.com/problems/DOMINANT2)

- **Difficulty Rating**: 1171
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, determine if there exists a "dominant" element. An element is considered dominant if its frequency (the number of times it appears in the array) is strictly greater than the frequency of any other element present in the array.

## Intuition & Mathematical Observation
To determine if a dominant element exists, we need to compare the frequencies of all unique elements:

1.  **Frequency Counting**: First, we count how many times each distinct number appears in the array.
2.  **Comparison**: Let the frequencies of the unique elements be $f_1, f_2, \dots, f_k$. If we sort these frequencies in descending order such that $f'_1 \ge f'_2 \ge \dots \ge f'_k$, the condition for a dominant element is simply $f'_1 > f'_2$.
3.  **Edge Cases**:
    *   If there is only one unique element in the array ($k=1$), it is automatically dominant because there are no other elements to compare its frequency against.
    *   If the two highest frequencies are equal ($f'_1 = f'_2$), no single element can be strictly greater than all others, so the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$
    - Counting frequencies takes $O(N)$.
    - Sorting the unique frequencies takes $O(K \log K)$, where $K$ is the number of unique elements ($K \le N$). Thus, the overall complexity is dominated by the sorting step: $O(N \log N)$.
- **Space Complexity**: $O(N)$
    - We use a frequency array (or map) of size $N$ to store the counts of elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An element is dominant if its frequency is strictly greater than the frequency 
 * of any other element in the array.
 */

void solve() {
    int n;
    cin >> n;
    
    // Frequency map to store counts of each element
    // Since 1 <= A_i <= N, a vector of size N+1 is sufficient
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }
    
    // Collect all non-zero frequencies
    vector<int> counts;
    for (int i = 1; i <= n; ++i) {
        if (freq[i] > 0) {
            counts.push_back(freq[i]);
        }
    }
    
    // If there's only one unique element, it's dominant
    if (counts.size() == 1) {
        cout << "YES" << "\n";
        return;
    }
    
    // Sort frequencies in descending order
    sort(counts.rbegin(), counts.rend());
    
    // Check if the highest frequency is strictly greater than the second highest
    if (counts[0] > counts[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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