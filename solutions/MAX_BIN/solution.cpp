#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * To maximize the value:
 * 1. The most significant bit (the leftmost bit) should be '1'. If S[0] is '0', 
 *    use 1 operation to flip it to '1'.
 * 2. Any remaining operations should be used to append '0's at the end. 
 *    Appending a '0' is equivalent to multiplying the current value by 2, 
 *    which is always better than flipping a '0' to '1' at a lower significance position.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // Step 1: If the first bit is '0', flip it to '1' using 1 operation.
    if (S[0] == '0') {
        S[0] = '1';
        K--;
    }

    // Step 2: Append K zeros at the end.
    // Each Type 1 operation adds a '0'. We have K operations left.
    string zeros(K, '0');
    cout << S << zeros << "\n";
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