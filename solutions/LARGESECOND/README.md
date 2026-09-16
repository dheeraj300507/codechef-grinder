# [Largest and Second Largest (LARGESECOND)](https://www.codechef.com/problems/LARGESECOND)

- **Difficulty Rating**: 928
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, the task is to find the sum of the two largest **distinct** integers present in the array. The problem guarantees that there will always be at least two distinct integers in the input.

## Intuition & Mathematical Observation
To find the two largest distinct integers, we need to filter out duplicates and identify the two highest values. 

1. **Handling Duplicates**: Since we only care about distinct values, a `std::set` in C++ is an ideal data structure. Inserting elements into a `std::set` automatically removes duplicates and keeps the elements in ascending order.
2. **Retrieving Values**: Once all elements are inserted into the set, the largest element will be at the end of the set, and the second largest will be the element immediately preceding it.
3. **Efficiency**: Given the constraints ($N \le 10^5$), an $O(N \log N)$ approach using a set is well within the time limits for the given test cases.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, where $N$ is the number of elements in the array. This is due to the $N$ insertions into the `std::set`, each taking $O(\log N)$ time.
- **Space Complexity**: $O(N)$ in the worst case, where all elements in the array are distinct and stored within the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the sum of the two largest distinct integers in an array.
 * Using a set to store unique elements is an efficient way to handle 
 * duplicates and maintain sorted order.
 */

void solve() {
    int N;
    cin >> N;
    
    // Use a set to store unique elements to easily find the two largest
    set<int> distinct_elements;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        distinct_elements.insert(val);
    }
    
    // Since the problem guarantees at least two distinct integers,
    // we can safely access the last two elements of the set.
    auto it = distinct_elements.end();
    int largest = *(--it);
    int second_largest = *(--it);
    
    cout << (long long)largest + second_largest << "\n";
}

int main() {
    // Fast I/O setup for performance
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