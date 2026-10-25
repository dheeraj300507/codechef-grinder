#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: SAMESAME
 * Approach: Brute force sliding window.
 * Complexity: O(T * N * M), where N, M <= 100.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;

    int min_hamming = M; // Maximum possible Hamming distance is M

    // Iterate through all possible starting positions of the substring in A
    for (int i = 0; i <= N - M; ++i) {
        int current_hamming = 0;
        // Compare substring A[i...i+M-1] with B
        for (int j = 0; j < M; ++j) {
            if (A[i + j] != B[j]) {
                current_hamming++;
            }
        }
        // Update the minimum Hamming distance found so far
        if (current_hamming < min_hamming) {
            min_hamming = current_hamming;
        }
    }

    cout << min_hamming << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}