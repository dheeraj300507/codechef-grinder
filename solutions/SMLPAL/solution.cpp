#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to form the smallest palindrome using X ones and Y twos.
 * Since X and Y are even, we can split them into two equal halves.
 * To minimize the number, we place all available 1s before the 2s in the first half.
 * 
 * Example: X=2, Y=2
 * Half: 1s = 2/2 = 1, 2s = 2/2 = 1.
 * First half: "12"
 * Full palindrome: "12" + "21" = "1221".
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    int half_ones = X / 2;
    int half_twos = Y / 2;

    string first_half = "";
    // To make the number smallest, put all 1s first, then all 2s
    for (int i = 0; i < half_ones; ++i) {
        first_half += '1';
    }
    for (int i = 0; i < half_twos; ++i) {
        first_half += '2';
    }

    string second_half = first_half;
    // Reverse the second half to complete the palindrome
    for (int i = 0; i < (int)first_half.length() / 2; ++i) {
        swap(second_half[i], second_half[second_half.length() - 1 - i]);
    }
    
    // Actually, simply reversing the string is easier:
    string result = first_half;
    string rev = first_half;
    for(int i = 0; i < (int)rev.length() / 2; ++i) swap(rev[i], rev[rev.length()-1-i]);
    
    cout << first_half << rev << endl;
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