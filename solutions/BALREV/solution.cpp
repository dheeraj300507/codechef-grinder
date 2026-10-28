#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to reverse any substring that has an equal number of 0s and 1s.
 * If we have a substring with equal 0s and 1s, we can effectively swap 0s and 1s 
 * within that range to sort them. 
 * 
 * More generally, if we can perform this operation any number of times, we can 
 * effectively move all 0s to the front and all 1s to the back. 
 * Why? Because any string with count(0) == count(1) can be sorted into 00...011...1 
 * by repeatedly applying the reversal operation. Since we can pick any valid 
 * substring, we can eventually sort the entire string by bringing all 0s to the 
 * left and all 1s to the right.
 * 
 * The lexicographically smallest string for a binary string is simply the string 
 * with all its 0s followed by all its 1s.
 * 
 * Complexity:
 * Time: O(N) per test case to count 0s and 1s and print them.
 * Space: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int count0 = 0;
    int count1 = 0;

    for (char c : A) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // The lexicographically smallest string is all 0s followed by all 1s.
    string result = "";
    for (int i = 0; i < count0; ++i) {
        result += '0';
    }
    for (int i = 0; i < count1; ++i) {
        result += '1';
    }

    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}