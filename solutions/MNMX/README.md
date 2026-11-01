# [Minimum Maximum (MNMX)](https://www.codechef.com/problems/MNMX)

- **Difficulty Rating**: 1392
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an array of $N$ integers, we perform an operation $N-1$ times. In each operation, we choose two adjacent elements, remove the larger one, and pay a cost equal to the value of the smaller one. The goal is to find the minimum total cost to reduce the array to a single element.

## Intuition & Mathematical Observation
To minimize the total cost, we want to use the smallest element in the array as the "cost" for as many operations as possible. 

1.  **The Strategy**: Let $min\_val$ be the smallest element in the array. Since we perform $N-1$ operations to reduce the array to one element, if we can ensure that $min\_val$ is the smaller element in every single operation, the total cost will be $(N-1) \times min\_val$.
2.  **Feasibility**: Because we can choose any two adjacent elements, we can always "bring" the global minimum to be adjacent to any other element in the array. By repeatedly pairing the global minimum with its neighbors, we can eliminate all other $N-1$ elements while paying $min\_val$ each time.
3.  **Data Types**: The constraints state $N \le 50,000$ and $A_i \le 100,000$. The maximum possible cost is approximately $50,000 \times 100,000 = 5 \times 10^9$. Since this exceeds the capacity of a 32-bit signed integer ($2 \times 10^9$), we must use `long long` to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to iterate through the array once to find the minimum element.
- **Space Complexity**: $O(1)$, as we only store the minimum value and the current input, rather than storing the entire array.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * To reduce an array of N elements to 1 element, we must perform N-1 operations.
 * In each operation, we remove the larger of two adjacent elements and pay the cost 
 * of the smaller one. To minimize the total cost, we want to ensure that the 
 * smallest element in the array is involved in every single operation.
 * 
 * Since we can always choose to pair the global minimum with any of its neighbors,
 * we can eliminate all other N-1 elements using the global minimum as the cost 
 * for each operation.
 * 
 * Total Cost = (N - 1) * min_element.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long min_val = 200000; // Initialize with a value larger than max Ai (10^5)
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // The minimum cost is (N-1) * min_val.
    // N <= 50,000 and Ai <= 100,000, so result can be up to 5 * 10^9.
    // This exceeds the range of a 32-bit signed integer, so long long is necessary.
    long long result = (long long)(n - 1) * min_val;
    cout << result << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```