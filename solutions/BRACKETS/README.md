# [Brackets (BRACKETS)](https://www.codechef.com/problems/BRACKETS)

- **Difficulty Rating**: 1207
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a valid parentheses sequence $A$, let $F(A)$ be the maximum nesting depth of the sequence. We need to construct a new valid parentheses sequence $B$ such that $F(B) = F(A)$ and the length of $B$ is minimal. If there are multiple such sequences, we output the one that is lexicographically smallest.

## Intuition & Mathematical Observation
1. **Calculating $F(A)$**: The maximum nesting depth $F(A)$ is equivalent to the maximum value the "balance" reaches while traversing the string, where '(' increments the balance and ')' decrements it.
2. **Minimal Length**: A valid parentheses sequence with a maximum nesting depth of $k$ must contain at least $k$ opening brackets and $k$ closing brackets. Therefore, the minimum length of such a sequence is $2k$.
3. **Lexicographical Smallest**: To make a sequence of length $2k$ lexicographically smallest, we want as many '(' as possible at the beginning. The sequence consisting of $k$ opening brackets followed by $k$ closing brackets (`((...))`) is the unique sequence that satisfies both the minimal length requirement and the lexicographical requirement.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the input string $A$. We iterate through the string once to find the maximum balance and then perform a simple loop to construct the output string.
- **Space Complexity**: $O(N)$ to store the input string and the resulting output string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * F(S) calculates the maximum nesting depth of a valid parentheses sequence.
 * Let max_balance = F(A).
 * We need to construct a valid parentheses sequence B such that F(B) = max_balance
 * and the length of B is minimal.
 * 
 * A valid parentheses sequence with maximum nesting depth 'k' must have at least
 * 'k' opening brackets and 'k' closing brackets. The shortest such sequence
 * is simply 'k' opening brackets followed by 'k' closing brackets: "((...))".
 */

void solve() {
    string A;
    cin >> A;
    
    int balance = 0;
    int max_balance = 0;
    
    // Calculate F(A)
    for (char c : A) {
        if (c == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance > max_balance) {
            max_balance = balance;
        }
    }
    
    // Construct the minimal sequence B: max_balance '(' followed by max_balance ')'
    string B = "";
    for (int i = 0; i < max_balance; ++i) {
        B += '(';
    }
    for (int i = 0; i < max_balance; ++i) {
        B += ')';
    }
    
    cout << B << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```