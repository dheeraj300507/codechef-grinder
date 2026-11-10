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