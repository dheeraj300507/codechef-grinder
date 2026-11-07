# [Palindrome Flipping (FLIPPAL)](https://www.codechef.com/problems/FLIPPAL)

- **Difficulty Rating**: 1173
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we are allowed to perform an operation where we choose any two indices $i$ and $j$ and flip the bits at these positions ($0 \to 1$ or $1 \to 0$). We need to determine if it is possible to transform the given string into a palindrome using any number of these operations.

## Intuition & Mathematical Observation
The key to this problem lies in understanding the invariant property of the operation:
1. **The Operation**: Flipping two bits changes the total count of $1$s in the string by $+2$, $0$, or $-2$. Crucially, this means the **parity of the number of $1$s remains invariant**.
2. **Palindrome Constraints**:
   - In a palindrome of length $N$, every bit at index $i$ must match the bit at index $N-1-i$.
   - If $N$ is **even**, every pair $(S[i], S[N-1-i])$ must consist of two identical bits. This implies that the total number of $1$s in the string must be even (since every $1$ must have a corresponding $1$ at the symmetric position).
   - If $N$ is **odd**, the middle element $S[N/2]$ does not have a pair. This middle element can be either $0$ or $1$, allowing us to "absorb" an odd count of $1$s. Therefore, any string of odd length can be transformed into a palindrome.

**Conclusion**:
- If $N$ is odd, the answer is always `YES`.
- If $N$ is even, the answer is `YES` if the total count of $1$s is even, and `NO` otherwise.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we iterate through the string once to count the number of $1$s.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Flipping two bits changes the total count of 1s by +2, 0, or -2.
 * The parity of the number of 1s remains invariant.
 * 
 * If N is odd, we can always form a palindrome because the middle element
 * can accommodate the parity of the 1s.
 * If N is even, we require an even number of 1s to satisfy the 
 * symmetric pairing requirement (S[i] == S[N-1-i]).
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // If N is odd, we can always make it a palindrome.
    if (N % 2 != 0) {
        cout << "YES" << "\n";
    } else {
        // If N is even, the total count of 1s must be even.
        int count1 = 0;
        for (char c : S) {
            if (c == '1') count1++;
        }
        
        if (count1 % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

int main() {
    // Optimize I/O operations
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