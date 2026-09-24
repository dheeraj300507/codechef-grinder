# [Transform the Expression (ONP)](https://www.codechef.com/problems/ONP)

- **Difficulty Rating**: 1300
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to convert a given infix expression (e.g., `(a+(b*c))`) into its equivalent Reverse Polish Notation (RPN), also known as postfix notation (e.g., `abc*+`). The expressions consist of lowercase alphabets, operators (`+`, `-`, `*`, `/`, `^`), and parentheses.

## Intuition & Mathematical Observation
This problem is a classic application of the **Shunting-yard algorithm** developed by Edsger Dijkstra. The core idea is to use a **stack** to manage operators based on their precedence while maintaining the relative order of operands.

1.  **Operands**: Whenever we encounter an operand (a-z), it is immediately appended to the output string because operands appear in the same relative order in both infix and postfix notations.
2.  **Parentheses**: 
    *   An opening parenthesis `(` signifies the start of a sub-expression, so we push it onto the stack.
    *   A closing parenthesis `)` signifies the end of a sub-expression. We pop operators from the stack and append them to the output until we encounter the matching `(`.
3.  **Operators**: When an operator is encountered, we must ensure that all operators currently on the stack with higher or equal precedence are processed (popped to the output) before pushing the current operator onto the stack. This ensures that the mathematical order of operations (PEMDAS/BODMAS) is preserved.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the expression string. Each character is pushed onto and popped from the stack at most once.
- **Space Complexity**: $O(N)$ in the worst case, as the stack may store up to $N$ operators if the expression is deeply nested or contains many operators.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Transform the Expression (ONP)
 * This is a classic application of the Shunting-yard algorithm to convert
 * infix expressions to Reverse Polish Notation (RPN).
 */

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    string result = "";

    for (char c : s) {
        if (isalpha(c)) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        } else {
            // Operator
            while (!st.empty() && st.top() != '(' && getPrecedence(st.top()) >= getPrecedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << "\n";
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