#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Buying New Tablet
 * Approach:
 * For each test case, iterate through all N tablets.
 * Check if the price P_i is less than or equal to the budget B.
 * If it is, calculate the area (W_i * H_i) and keep track of the maximum area found so far.
 * If no tablet is affordable, output "no tablet".
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1)
 */

void solve() {
    int N;
    long long B;
    cin >> N >> B;

    long long max_area = -1;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        long long W, H, P;
        cin >> W >> H >> P;

        if (P <= B) {
            long long current_area = W * H;
            if (current_area > max_area) {
                max_area = current_area;
            }
            found = true;
        }
    }

    if (!found) {
        cout << "no tablet" << "\n";
    } else {
        cout << max_area << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}