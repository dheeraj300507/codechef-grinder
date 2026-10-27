# [Weapon Value (SC31)](https://www.codechef.com/problems/SC31)

- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
In a tournament, $N$ participants each possess a set of 10 types of weapons, represented by a binary string of length 10. When two participants battle, weapons of the same type are destroyed (this corresponds to the XOR operation). The winner keeps the remaining weapons. We need to determine the total number of weapons remaining after all participants have battled, regardless of the tournament structure.

## Intuition & Mathematical Observation
The core of the problem lies in the properties of the **XOR** operation:
1. **Commutativity and Associativity**: The order in which the battles occur does not change the final outcome.
2. **Self-Inverse**: $x \oplus x = 0$. This perfectly models the "destruction" of weapons of the same type.

Because the final state is simply the XOR sum of all participants' weapon sets, we do not need to simulate the tournament bracket. We can simply maintain a running XOR sum of all input strings. Since the string length is fixed at 10, we can represent each string as an integer bitmask or process them character by character. The final answer is the count of set bits (population count) in the resulting XOR sum.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times L)$, where $T$ is the number of test cases, $N$ is the number of participants, and $L=10$ is the length of the binary string. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(L)$ (or $O(1)$ effectively), as we only need to store the current XOR sum and the input string of length 10.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that when two contestants battle, weapons of the same type
 * are destroyed (XOR operation). The winner collects the remaining weapons of the loser.
 * This implies that the final set of weapons held by the winner is the XOR sum
 * of the initial weapon sets of all N participants.
 * 
 * Let S_i be the binary string representing the weapons of participant i.
 * The final state is S_1 XOR S_2 XOR ... XOR S_N.
 * Since the XOR operation is associative and commutative, the order of battles
 * does not matter. The final result is always the same regardless of the tournament bracket.
 */

void solve() {
    int N;
    cin >> N;
    
    // We can represent the 10 weapons as a bitmask or an integer array.
    // Since the length is fixed at 10, an integer XOR sum is sufficient.
    int result_mask = 0;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        // Convert binary string to integer bitmask
        int current_mask = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '1') {
                current_mask |= (1 << (9 - j));
            }
        }
        
        // XOR the current participant's weapons into the total
        result_mask ^= current_mask;
    }
    
    // Count the number of set bits in the final mask
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if ((result_mask >> i) & 1) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```