#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X represented by binary string S.
 * We want to maximize X ^ (X >> Y) where 1 <= Y <= |S|.
 * Let N be the length of the string.
 * X is a number with N bits.
 * When we perform X ^ (X >> Y), we are essentially XORing the most significant bits
 * of X with the bits shifted right by Y.
 * 
 * Let the binary representation be S = s_0 s_1 ... s_{N-1}.
 * The most significant bit (s_0) is always 1 (unless X=0, but the problem implies 
 * standard binary representation).
 * 
 * When we XOR X with (X >> Y), the bits from index 0 to N-1-Y are affected.
 * Specifically, the bit at position i (from left, 0-indexed) becomes s_i ^ s_{i+Y}.
 * To maximize the resulting number, we want the most significant bit that changes 
 * to become 1. Since the original MSB is 1, if we can make the MSB of the result 1,
 * we want the first position where the XOR operation flips a 0 to a 1 or keeps a 1.
 * 
 * Actually, a simpler observation:
 * The operation X ^ (X >> Y) is equivalent to taking the prefix of length (N-Y) 
 * of the binary string and XORing it with the string shifted.
 * The most significant bit of the result will always be 1 (because the MSB of X 
 * is 1 and the MSB of (X >> Y) is 0 for Y >= 1).
 * To maximize the value, we want the first '0' after the first '1' to be flipped 
 * to '1' as early as possible, or simply maximize the prefix.
 * 
 * By testing, the optimal Y is the number of consecutive '1's starting from the 
 * most significant bit (index 0). If the string is "11101", Y=3 gives the best result.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int y = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            y++;
        } else {
            break;
        }
    }
    
    // The optimal Y is the length of the prefix of 1s.
    // If the string is "110", Y=2. If "101", Y=1.
    // This logic holds because we want to flip the first '0' we encounter 
    // to '1' to maximize the value.
    cout << y << "\n";
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