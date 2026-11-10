# [Spoon in Matrix (SPOON)](https://www.codechef.com/problems/SPOON)

- **Difficulty Rating**: 1303
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a grid of characters of size $R \times C$, determine if the word "spoon" (case-insensitive) exists anywhere in the grid. The word can appear horizontally (left to right) or vertically (top to bottom). If the word is found, output "There is a spoon!"; otherwise, output "There is indeed no spoon!".

## Intuition & Mathematical Observation
Since the constraints are small ($R, C \le 100$), we can perform a brute-force search without worrying about time limits. 

1. **Case Insensitivity**: The problem states the search is case-insensitive. We can handle this by converting every character to lowercase (using `tolower()`) before comparing it with the target string "spoon".
2. **Horizontal Search**: We iterate through each row of the matrix and check if the substring "spoon" exists within that row string.
3. **Vertical Search**: We construct strings representing each column by iterating through the rows for a fixed column index $j$. Once the column string is built, we check if "spoon" exists within it.
4. **Efficiency**: By checking row by row and column by column, we ensure we cover all possible horizontal and vertical occurrences. The first time we find a match, we can immediately print the result and return to the next test case.

## Complexity Analysis
- **Time Complexity**: $O(T \times R \times C)$. For each test case, we traverse the matrix once to check rows and once to check columns. Since $R, C \le 100$, the total operations per test case are roughly $2 \times 100 \times 100 = 20,000$, which easily fits within the 0.5s time limit.
- **Space Complexity**: $O(R \times C)$ to store the matrix. The auxiliary space for column strings is $O(R)$ per iteration.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Spoon in Matrix
 * The task is to find the word "spoon" (case-insensitive) in a matrix,
 * either horizontally (left to right) or vertically (top to bottom).
 * 
 * Constraints: R, C <= 100, T <= 100.
 * Time Complexity: O(T * R * C), which is well within the 0.5s limit.
 */

bool isSpoon(string s) {
    if (s.length() < 5) return false;
    string target = "spoon";
    for (int i = 0; i <= (int)s.length() - 5; ++i) {
        bool match = true;
        for (int j = 0; j < 5; ++j) {
            if (tolower(s[i + j]) != target[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

void solve() {
    int R, C;
    cin >> R >> C;
    vector<string> matrix(R);
    for (int i = 0; i < R; ++i) {
        cin >> matrix[i];
    }

    // Check rows
    for (int i = 0; i < R; ++i) {
        if (isSpoon(matrix[i])) {
            cout << "There is a spoon!" << "\n";
            return;
        }
    }

    // Check columns
    for (int j = 0; j < C; ++j) {
        string col = "";
        for (int i = 0; i < R; ++i) {
            col += matrix[i][j];
        }
        if (isSpoon(col)) {
            cout << "There is a spoon!" << "\n";
            return;
        }
    }

    cout << "There is indeed no spoon!" << "\n";
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