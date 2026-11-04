#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is initially sorted.
 * In each operation, we remove the smallest element (A[left]) and the largest element (A[right]),
 * and append their sum to the back.
 * 
 * Since the array is sorted, the minimum is always at the current 'left' pointer,
 * and the maximum is always at the current 'right' pointer.
 * After removing them, the new sum is appended. Since the sum of the min and max
 * is likely larger than or equal to the current elements, the new elements
 * will effectively be added to the end of the remaining sorted sequence.
 * 
 * We can use a deque or two pointers to manage the original array and a queue
 * to store the newly generated sums.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Deque to store the original elements
    deque<long long> dq;
    for (long long x : A) {
        dq.push_back(x);
    }

    // Queue to store the newly generated sums
    queue<long long> q;

    for (int i = 0; i < K; ++i) {
        long long min_val, max_val;

        // Get min: compare front of dq and front of q
        if (q.empty() || (!dq.empty() && dq.front() <= q.front())) {
            min_val = dq.front();
            dq.pop_front();
        } else {
            min_val = q.front();
            q.pop();
        }

        // Get max: compare back of dq and back of q
        if (q.empty() || (!dq.empty() && dq.back() >= q.back())) {
            max_val = dq.back();
            dq.pop_back();
        } else {
            max_val = q.back();
            q.pop();
        }

        q.push(min_val + max_val);
    }

    // Collect remaining elements
    vector<long long> result;
    while (!dq.empty()) {
        result.push_back(dq.front());
        dq.pop_front();
    }
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    // The problem implies the final array should be sorted
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
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