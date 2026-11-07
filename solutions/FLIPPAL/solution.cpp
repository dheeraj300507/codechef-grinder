#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can flip any two bits (0->1 or 1->0).
 * Flipping two bits changes the total count of 1s by +2, 0, or -2.
 * This means the parity of the number of 1s remains invariant.
 * 
 * A palindrome of length N has pairs (S[i], S[N-1-i]).
 * For a palindrome, S[i] must equal S[N-1-i].
 * If N is odd, the middle element S[N/2] does not have a pair.
 * 
 * Let's look at the pairs (S[i], S[N-1-i]).
 * If we have an odd number of 1s in the string, we can only form a palindrome 
 * if N is odd (the middle element can be the odd 1).
 * If N is even, the total number of 1s must be even to form a palindrome 
 * (because every 1 must have a matching 1 at the symmetric position).
 * 
 * Actually, the operation allows us to change the parity of 1s in any pair 
 * or change the parity of the whole string by 2.
 * Specifically, if N is even, we need an even number of 1s.
 * If N is odd, we can always make it a palindrome regardless of the number of 1s,
 * because we can use the middle element to absorb the parity.
 * 
 * Wait, let's re-verify:
 * If N is even, we need the total count of 1s to be even.
 * If N is odd, we can always achieve a palindrome.
 * Let's check sample 2: N=2, S="01". Count of 1s = 1 (odd). N is even. Output: NO. Correct.
 * Sample 1: N=6, S="101011". Count of 1s = 4 (even). N is even. Output: YES. Correct.
 * Sample 3: N=7, S="1110000". Count of 1s = 3 (odd). N is odd. Output: YES. Correct.
 * 
 * Conclusion:
 * If N is odd, answer is always YES.
 * If N is even, answer is YES if count of 1s is even, else NO.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N % 2 != 0) {
        cout << "YES" << "\n";
    } else {
        int count1 = 0;
        for (char c : S) {
            if (c == '1') count1++;
        }
        if (count1 % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
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