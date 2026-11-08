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
 * 
 * For example, if F(A) = 3, the shortest sequence is "((()))".
 * This sequence has F(B) = 3 and length 6.
 * Any sequence with F(B) = k must have length at least 2k.
 * The lexicographically smallest sequence of length 2k with F(B) = k is indeed
 * "((...))" because '(' is lexicographically smaller than ')'.
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