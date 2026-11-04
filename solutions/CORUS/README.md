# [Isolation Centers (CORUS)](https://www.codechef.com/problems/CORUS)

- **Difficulty Rating**: 1305
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string $S$ representing the virus types of $N$ infected people. We have $C$ isolation centers available. For each query, we are given a value $C$, representing the capacity of each isolation center. Each center can hold at most one person of a specific virus type. We need to calculate how many people will remain in the "pending queue" (i.e., those who cannot be accommodated in any isolation center) for each given $C$.

## Intuition & Mathematical Observation
1. **Frequency Counting**: Since there are only 26 types of viruses ('a' through 'z'), we first count the frequency of each virus type in the input string $S$. Let `freq[i]` be the number of people infected with the $i$-th letter of the alphabet.
2. **Capacity Logic**: If we have $C$ isolation centers, each center can take one person of a specific virus type. Therefore, for a virus type with `freq[i]` people, we can isolate $\min(\text{freq}[i], C)$ people.
3. **Pending Queue**: The number of people of virus type $i$ who cannot be isolated is $\max(0, \text{freq}[i] - C)$.
4. **Total Pending**: The total number of people in the pending queue for a given $C$ is the sum of these values across all 26 virus types:
   $$\text{Total Pending} = \sum_{i=0}^{25} \max(0, \text{freq}[i] - C)$$

## Complexity Analysis
- **Time Complexity**: 
    - Preprocessing: $O(N)$ to iterate through the string and count frequencies.
    - Query: $O(26)$ per query, as we iterate through the frequency array of size 26.
    - Total: $O(T \times (N + Q \times 26))$, which efficiently handles the constraints ($N, Q \le 10^5$).
- **Space Complexity**: $O(1)$ (or $O(26)$), as we only store the frequency counts for the 26 lowercase English letters.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 26 types of viruses ('a' through 'z').
 * For each virus type, let count[char] be the number of people infected by that virus.
 * We have C isolation centers.
 * For a specific virus type with count[char] people:
 * - Each isolation center can hold at most 1 person of this virus type.
 * - If we have C isolation centers, we can place min(count[char], C) people in isolation.
 * - The remaining people, max(0, count[char] - C), must go to the pending queue.
 * 
 * Total people in the pending queue = sum over all 26 characters of max(0, count[char] - C).
 */

void solve() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    // Count frequency of each character
    vector<long long> freq(26, 0);
    for (char c : S) {
        freq[c - 'a']++;
    }

    // Process each query
    while (Q--) {
        long long C;
        cin >> C;
        
        long long pending_queue_size = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > C) {
                pending_queue_size += (freq[i] - C);
            }
        }
        cout << pending_queue_size << "\n";
    }
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