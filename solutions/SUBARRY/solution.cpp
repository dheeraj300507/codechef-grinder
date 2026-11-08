#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "interesting value" of a subarray is min(subarray) * max(subarray).
 * We want to find the global minimum and maximum of this value over all possible subarrays.
 * 
 * Consider a subarray of length 1: [A[i]]. The value is A[i] * A[i] = A[i]^2.
 * If we expand a subarray, the min can only decrease (or stay same) and the max can only increase (or stay same).
 * 
 * For the maximum possible value:
 * If all numbers are positive, the maximum is (max(A))^2.
 * If there are negative numbers, the maximum could be (min(A))^2 if min(A) is a large negative number.
 * Thus, the maximum is max(max(A)^2, min(A)^2).
 * 
 * For the minimum possible value:
 * If there are negative numbers, we can potentially get a very small (large negative) value by multiplying 
 * a large positive number and a large negative number.
 * The minimum value will be min(min(A) * max(A), min(A) * min(abs(A)), etc).
 * Actually, for any array, the minimum value is simply min(min(A) * max(A), min(A) * min(abs(A)) is not quite right).
 * Let's re-evaluate:
 * The minimum value is min(min_val * max_val) over all subarrays.
 * Since we can pick a subarray of length 1, we have A[i]^2.
 * If we pick a subarray [min_element, max_element], the product is min_element * max_element.
 * The minimum possible value is min(min_element * max_element) across all possible subarrays.
 * This is achieved by either:
 * 1. The smallest element * the largest element (if we consider the whole array).
 * 2. The smallest element * the largest element (if we consider any subarray).
 * Actually, it is proven that the minimum value is min(min(A)*max(A), min(A)*min(abs(A))) is not needed.
 * The minimum value is simply min(min_element * max_element) where min_element and max_element are 
 * the global min and global max of the entire array, OR the product of the smallest and largest 
 * values available in the array.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long min_val = a[0];
    long long max_val = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    // The maximum possible value is either the square of the largest absolute value.
    long long ans_max = max(min_val * min_val, max_val * max_val);

    // The minimum possible value is min(min_val * max_val, min_val * min_val, max_val * max_val)
    // Actually, for any subarray, the product is bounded by the global min and max.
    // The minimum value is min(min_val * max_val, 0 if 0 exists, etc).
    // The simplest way to get the minimum is to check the product of global min and max,
    // and the squares of the extremes.
    long long ans_min = min({min_val * max_val, min_val * min_val, max_val * max_val});

    cout << ans_min << " " << ans_max << "\n";
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