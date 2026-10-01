#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size N. We can repeatedly add the last element to the 
 * second-to-last element and remove the last element.
 * This means we can reduce the array to any size k (where 1 <= k <= N) 
 * by merging the last (N-k) elements into the k-th element.
 * 
 * Specifically, if we want to reach a state where the array has size k,
 * the new elements will be:
 * A[1], A[2], ..., A[k-1], (A[k] + A[k+1] + ... + A[N])
 * 
 * We want to know if there exists some k (1 <= k <= N) such that all elements
 * in the resulting array are even.
 * 
 * For a fixed k:
 * - A[1], A[2], ..., A[k-1] must all be even.
 * - The sum (A[k] + A[k+1] + ... + A[N]) must be even.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We can choose to stop at any size k from 1 to N.
    // Check if any k works.
    bool possible = false;
    for (int k = 1; k <= N; ++k) {
        bool ok = true;
        
        // Check if A[0]...A[k-2] are even
        for (int i = 0; i < k - 1; ++i) {
            if (A[i] % 2 != 0) {
                ok = false;
                break;
            }
        }
        
        if (!ok) continue;
        
        // Check if the sum of the remaining suffix is even
        long long suffix_sum = 0;
        for (int i = k - 1; i < N; ++i) {
            suffix_sum += A[i];
        }
        
        if (suffix_sum % 2 == 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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