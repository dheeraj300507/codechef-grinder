#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Transform the Expression (ONP)
 * This is a classic application of the Shunting-yard algorithm to convert
 * infix expressions to Reverse Polish Notation (RPN).
 * 
 * Logic:
 * 1. If the character is an operand (a-z), add it to the output.
 * 2. If the character is '(', push it onto the stack.
 * 3. If the character is ')', pop from the stack to the output until '(' is found.
 * 4. If the character is an operator (+, -, *, /, ^), pop operators from the stack
 *    to the output that have higher or equal precedence, then push the current operator.
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