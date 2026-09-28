#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length 3. We need to determine if it can be 
 * rearranged to form the word "cat".
 * 
 * A string of length 3 can be rearranged to form "cat" if and only if 
 * it contains exactly one 'c', one 'a', and one 't'.
 * 
 * Approach:
 * 1. Sort the input string S.
 * 2. Compare the sorted string with "act" (which is "cat" sorted).
 * 3. If they are equal, output "Yes", otherwise "No".
 */

void solve() {
    string s;
    if (!(cin >> s)) return;
    
    sort(s.begin(), s.end());
    
    if (s == "act") {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem description implies a single string input, 
    // but standard competitive programming practice often involves 
    // test cases. Given the problem description "The first and only line 
    // of input contains a single string S", we handle one case.
    solve();
    
    return 0;
}