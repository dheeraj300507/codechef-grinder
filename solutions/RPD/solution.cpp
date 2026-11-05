#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of N integers (2 <= N <= 100).
 * We need to find two different elements A[i] and A[j] (i != j) such that
 * the sum of digits of their product (A[i] * A[j]) is maximized.
 * 
 * Constraints:
 * N <= 100
 * A[i] <= 10^4
 * 
 * Since N is small (up to 100), an O(N^2) approach is perfectly acceptable.
 * 100 * 100 = 10,000 operations per test case.
 * With T = 100, total operations are ~1,000,000, which easily fits in 1s.
 */

// Function to calculate the sum of digits of a number
int sumOfDigits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int max_sum = 0;

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long product = A[i] * A[j];
            int current_sum = sumOfDigits(product);
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}