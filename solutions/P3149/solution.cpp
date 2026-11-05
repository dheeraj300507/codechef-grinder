#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the maximum subarray sum by turning some elements into 0.
 * If all elements are negative, the maximum subarray sum is 0 (empty subarray). 
 * We can't increase this, so 0 operations are needed.
 * 
 * If there are positive elements, we want to keep all positive elements and 
 * turn all negative elements into 0, provided that turning a negative element 
 * into 0 helps connect two positive segments or removes a negative value that 
 * would otherwise decrease the sum of a subarray containing positive values.
 * 
 * Actually, the goal is to make the sum of the subarray containing all positive 
 * numbers as large as possible. If we have a sequence of positive numbers 
 * separated by negative numbers, we should turn all those negative numbers into 0.
 * 
 * The minimum number of operations is simply the count of negative numbers 
 * that lie between the first positive number and the last positive number in the array.
 * If there are no positive numbers, the answer is 0.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int first_pos = -1;
    int last_pos = -1;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > 0) {
            if (first_pos == -1) first_pos = i;
            last_pos = i;
        }
    }

    // If no positive numbers exist, max subarray sum is 0, 0 operations needed.
    if (first_pos == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count negative numbers between the first and last positive number.
    int ops = 0;
    for (int i = first_pos; i <= last_pos; ++i) {
        if (A[i] < 0) {
            ops++;
        }
    }
    cout << ops << "\n";
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