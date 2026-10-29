# [Equal Card Game (EQCARDGAME)](https://www.codechef.com/problems/EQCARDGAME)

- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has a standard deck of 52 cards. She wants to distribute these cards equally among $K$ people. If the cards cannot be distributed equally, she must discard the minimum number of cards such that the remaining cards can be divided equally among the $K$ people. We need to find the minimum number of cards to discard.

## Intuition & Mathematical Observation
To distribute the cards equally among $K$ people, the number of cards remaining ($R$) must be a multiple of $K$. Since we start with 52 cards, we are looking for the largest integer $R \le 52$ such that $R$ is divisible by $K$.

The number of cards to discard is $52 - R$. 
Mathematically, the remainder of $52$ divided by $K$ (denoted as $52 \pmod K$) represents exactly how many cards are "extra" and prevent the total from being perfectly divisible by $K$. 

- If $52$ is already divisible by $K$, then $52 \pmod K = 0$, and we discard 0 cards.
- If $52$ is not divisible by $K$, then $52 \pmod K$ gives the exact count of cards that must be removed to reach the nearest multiple of $K$ below 52.

Thus, the answer is simply `52 % K`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the modulo operation is performed in constant time. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has 52 cards. There are K people in total.
 * She needs to distribute the remaining cards equally among K people.
 * Let R be the number of cards remaining after discarding some cards.
 * R must be a multiple of K, and R <= 52.
 * To minimize the number of discarded cards (52 - R), we need to maximize R.
 * R = 52 - (52 % K).
 * The number of discarded cards is 52 % K.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int k;
        cin >> k;
        
        // The number of cards to discard is simply 52 modulo K.
        // If 52 is divisible by K, 52 % K is 0, which is correct.
        // If not, 52 % K gives the remainder that must be removed to make it divisible.
        int result = 52 % k;
        
        cout << result << "\n";
    }
    
    return 0;
}
```