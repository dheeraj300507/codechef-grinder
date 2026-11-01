#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Find Second Largest
 * Approach: Store the three integers in a vector, sort them, 
 * and pick the middle element (index 1).
 * Time Complexity: O(1) as there are always exactly 3 elements.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies reading three integers.
    // Based on the sample input format, we read A, B, and C.
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    vector<long long> v = {a, b, c};
    sort(v.begin(), v.end());

    // The second largest element in a sorted list of 3 is at index 1.
    cout << v[1] << "\n";

    return 0;
}