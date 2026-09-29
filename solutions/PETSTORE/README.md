# [Pet Store (PETSTORE)](https://www.codechef.com/problems/PETSTORE)

- **Difficulty Rating**: 1126
- **Solved in**: 2 attempt(s)

## Problem Summary
Alice and Bob are given a collection of $N$ animals, where each animal belongs to a specific type. They want to divide these animals between themselves such that both Alice and Bob end up with the exact same multiset of animals. We need to determine if such a division is possible.

## Intuition & Mathematical Observation
To ensure Alice and Bob have the same multiset of animals, every animal type must be distributed equally between them. 

1. Let $C(x)$ be the total count of animals of type $x$ in the input.
2. If Alice takes $k_x$ animals of type $x$, Bob must take the remaining $C(x) - k_x$ animals.
3. For their multisets to be identical, Alice and Bob must possess the same number of animals of type $x$. Therefore, $k_x = C(x) - k_x$.
4. This simplifies to $2 \cdot k_x = C(x)$, which implies that $C(x)$ must be an **even number** for every animal type present in the collection.

If any animal type has an odd total count, it is impossible to split that type equally between two people, making the division impossible.

## Complexity Analysis
- **Time Complexity**: $O(N + K)$, where $N$ is the number of animals and $K$ is the range of animal types (100). Since we iterate through the input once and then check the frequency array, the complexity is linear.
- **Space Complexity**: $O(K)$, where $K=101$. We use a fixed-size frequency array to store the counts of animal types, which is effectively $O(1)$ space.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob must end up with the exact same multiset of animals.
 * Let the total count of animal type 'x' be C(x).
 * If Alice takes k_x animals of type 'x', Bob must take C(x) - k_x animals.
 * For their multisets to be identical, Alice and Bob must have the same number 
 * of each animal type: k_x = C(x) - k_x, which implies 2 * k_x = C(x).
 * Therefore, C(x) must be even for all types 'x'.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Since A_i is small (1 to 100), a frequency array is optimal.
    vector<int> counts(101, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a >= 1 && a <= 100) {
            counts[a]++;
        }
    }
    
    // Check if every animal type has an even count.
    bool possible = true;
    for (int i = 1; i <= 100; ++i) {
        if (counts[i] % 2 != 0) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for competitive programming
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