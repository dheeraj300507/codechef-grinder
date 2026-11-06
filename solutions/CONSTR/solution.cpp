#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can replace a character with 3 occurrences of itself.
 * This means any block of identical consecutive characters of length L 
 * can be reduced to a single character if L is a multiple of 3, 
 * or if we can reach the target count by repeatedly applying the operation.
 * Actually, the operation allows us to replace 1 character with 3.
 * This means 1 -> 3 -> 5 -> 7... (each operation adds 2 to the count).
 * Wait, the operation is: replace 1 char with 3.
 * So 1 -> 3. If we have 3, we can replace one of them to get 3+2 = 5.
 * Generally, if we have a block of length L, we can obtain it from a single 
 * character if L is odd. 
 * However, the problem asks for the minimum length string S.
 * If we have a block of identical characters of length L, we can reduce it 
 * to a single character if L is odd. If L is even, we need 2 characters 
 * (e.g., 2 -> 4 -> 6...).
 * 
 * Let's re-examine:
 * If we have 'aaa', we can get it from 'a'.
 * If we have 'aa', we cannot get it from 'a' because 1 -> 3.
 * If we have 'aaaa', we can get it from 'aa' (replace one 'a' with 'aaa' -> 'aaaa').
 * So, for any block of identical characters of length L:
 * - If L is odd, we can reduce it to 1 character.
 * - If L is even, we can reduce it to 2 characters.
 * 
 * Example 1: 'aaabbb' -> 'a' (3 is odd) and 'b' (3 is odd) -> 'ab'. Correct.
 * Example 2: 'abbbbbc' -> 'a' (1 is odd), 'bbbbb' (5 is odd) -> 'b', 'c' (1 is odd) -> 'abc'. Correct.
 * Example 3: 'abcd' -> 'a', 'b', 'c', 'd' -> 'abcd'. Correct.
 */

void solve() {
    int N;
    cin >> N;
    string U;
    cin >> U;

    string S = "";
    int i = 0;
    while (i < N) {
        int count = 0;
        char current = U[i];
        while (i < N && U[i] == current) {
            count++;
            i++;
        }
        
        // If count is odd, we need 1 char. If even, we need 2.
        if (count % 2 != 0) {
            S += current;
        } else {
            S += current;
            S += current;
        }
    }
    cout << S << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}