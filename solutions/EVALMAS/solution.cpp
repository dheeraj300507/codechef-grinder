#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N+1 ones and N operators.
 * The expression is evaluated as:
 * 1. All multiplications are performed first.
 * 2. Then additions and subtractions are performed.
 * 
 * Let the expression be 1 op1 1 op2 1 ... opN 1.
 * Since all numbers are 1, any multiplication 1*1 results in 1.
 * Effectively, we can group the expression into terms separated by '+' or '-'.
 * A multiplication chain like 1*1*1...*1 is always 1.
 * 
 * Let's use one '*' to make a block of 1s.
 * If we use k '*' operators, we effectively have (N-k) additions/subtractions.
 * The maximum value we can reach is N+1 (all '+').
 * The minimum value we can reach is 1 - N (all '-').
 * However, we can use '*' to keep the value 1.
 * 
 * Strategy:
 * 1. Start with a base value of 1.
 * 2. We have N slots. Let's use some '*' to keep the value 1, and the rest to add/subtract.
 * 3. If we use 'k' multiplications, we have N-k operators left to change the value.
 * 4. Each '+' adds 1, each '-' subtracts 1.
 * 5. We need to reach X starting from 1.
 * 6. Max possible with N operators: 1 + N (if all are '+').
 * 7. Min possible with N operators: 1 - N (if all are '-').
 * 8. If X is outside [1-N, N+1], output -1.
 * 9. Otherwise, we can use some '*' to "waste" operators and then use '+' or '-' to reach X.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;

    if (X > N + 1 || X < 1 - N) {
        cout << -1 << "\n";
        return;
    }

    string res = "";
    long long current_val = 1;
    int stars = 0;
    
    // We need to reach X. 
    // We can use '*' to keep the value 1, then use '+' or '-' to adjust.
    // Let's use as many '*' as possible to reach the target.
    // Actually, a simpler approach:
    // We have N positions. Let's fill them with '*' first, then adjust.
    // But '*' doesn't change the value 1.
    // Let's use 'k' stars and N-k '+' or '-'.
    // Value = 1 + (count of +) - (count of -).
    // Total operators = k + (count of +) + (count of -) = N.
    
    // Let's try to use as many '*' as possible.
    // If we use N stars, value is 1. If X=1, we are done.
    // If X != 1, we need to use some '+' or '-'.
    
    string s(N, '*');
    long long val = 1;
    
    // We need to change val to X using N operators.
    // Each '+' increases val by 1, each '-' decreases val by 1.
    // We have N slots.
    for (int i = 0; i < N; ++i) {
        if (val < X) {
            s[i] = '+';
            val++;
        } else if (val > X) {
            s[i] = '-';
            val--;
        } else {
            s[i] = '*';
        }
    }
    
    if (val == X) {
        cout << s << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}