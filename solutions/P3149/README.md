# [Easy Subarray Sum (P3149)](https://www.codechef.com/problems/P3149)

- **Difficulty Rating**: 1253
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of integers, we want to maximize the sum of a subarray by performing an operation: choosing any element and changing its value to $0$. We need to find the minimum number of operations required to achieve the maximum possible subarray sum.

## Intuition & Mathematical Observation
1. **Maximum Possible Sum**: The maximum possible sum of a subarray is the sum of all positive integers in the array. Any negative number included in a subarray will decrease its total sum.
2. **Strategy**: To achieve the maximum sum, we want to include all positive numbers in a single subarray. If there are negative numbers between the first positive number and the last positive number, they will "break" the continuity of our desired subarray.
3. **The Operation**: By turning all negative numbers located between the first and last positive numbers into $0$, we effectively merge all positive segments into one large subarray whose sum is the total sum of all positive elements in the array.
4. **Edge Cases**:
   - If there are no positive numbers, the maximum subarray sum is $0$ (by choosing an empty subarray or a single $0$), requiring $0$ operations.
   - If there is only one positive number, no negative numbers need to be changed, requiring $0$ operations.
5. **Conclusion**: The minimum number of operations is simply the count of all negative numbers that appear between the index of the first positive number and the index of the last positive number.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform a single pass to find the indices of the first and last positive numbers, and a second pass (or combined) to count the negative numbers in that range.
- **Space Complexity**: $O(N)$ to store the array, though this could be optimized to $O(1)$ by processing the input on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the subarray sum, we must include all positive numbers.
 * Any negative number between the first and last positive number must be 
 * turned into 0 to ensure the subarray sum remains the sum of all positive 
 * integers.
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
```