# [Card Removal (REMOVECARDS)](https://www.codechef.com/problems/REMOVECARDS)

- **Difficulty Rating**: 1039
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array of $N$ cards, each having a specific value. Your goal is to make all remaining cards have the same value by removing some cards. The objective is to minimize the total number of cards removed.

## Intuition & Mathematical Observation
To minimize the number of cards removed, we must maximize the number of cards kept. Since all kept cards must have the same value, we should identify the value that appears most frequently in the array.

1. Let $N$ be the total number of cards.
2. Let $f(x)$ be the frequency of a card value $x$ in the array.
3. If we choose to keep all cards with value $x$, we keep $f(x)$ cards.
4. The number of removals required for a specific value $x$ is $N - f(x)$.
5. To minimize this value, we must maximize $f(x)$.

Therefore, the minimum number of moves is $N - \max(f(x))$ for all $x$ present in the array. Given the constraints ($A_i \le 10$), we can easily track frequencies using a small array or a hash map.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of cards. We iterate through the input array once to count frequencies and then iterate through the fixed-size frequency array (size 10).
- **Space Complexity**: $O(1)$, as we use a frequency array of size 11, which is constant regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards with values A_i. We want to keep only cards that have the same value.
 * To minimize the number of moves (removals), we should maximize the number of cards 
 * we keep.
 * 
 * If we decide to keep all cards with value 'x', the number of cards we keep is 
 * equal to the frequency of 'x' in the input array.
 * The number of moves required would then be N - (frequency of 'x').
 * 
 * To minimize the moves, we need to maximize the frequency of 'x'.
 * Therefore, the answer is N - (maximum frequency of any value present in the array).
 */

void solve() {
    int N;
    cin >> N;
    
    // Since A_i is between 1 and 10, we can use a frequency array of size 11.
    int freq[11] = {0};
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }
    
    int max_freq = 0;
    for (int i = 1; i <= 10; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    // The minimum moves is total cards minus the count of the most frequent card.
    cout << (N - max_freq) << "\n";
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