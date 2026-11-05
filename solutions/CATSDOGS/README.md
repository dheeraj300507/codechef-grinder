# [Cats and Dogs (CATSDOGS)](https://www.codechef.com/problems/CATSDOGS)

- **Difficulty Rating**: 1389
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $C$ cats and $D$ dogs. Each animal has 4 legs. Dogs cannot ride on anything, but cats can ride on dogs, with a maximum of 2 cats per dog. When a cat rides on a dog, its legs are not counted toward the total $L$. We need to determine if it is possible for the total number of legs visible on the ground to be exactly $L$.

## Intuition & Mathematical Observation
To solve this, we define the bounds for the number of legs $L$ that can be visible:

1.  **Divisibility Constraint**: Since every animal (cat or dog) has 4 legs, the total number of legs $L$ must be a multiple of 4. If $L \% 4 \neq 0$, it is impossible.
2.  **Maximum Legs**: The maximum number of legs occurs when every single animal is standing on the ground.
    *   $Max\_Legs = (C + D) \times 4$
3.  **Minimum Legs**: The minimum number of legs occurs when we maximize the number of cats riding on dogs.
    *   Each dog can carry up to 2 cats.
    *   Total cats that can be carried = $2 \times D$.
    *   Cats that *must* be on the ground = $\max(0, C - 2 \times D)$.
    *   $Min\_Legs = (D + \text{cats\_on\_ground}) \times 4$.
4.  **Conclusion**: If $L$ is a multiple of 4 and $Min\_Legs \leq L \leq Max\_Legs$, then it is possible to have $L$ legs on the ground.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated bounds.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Total animals: C cats, D dogs.
 * - Each dog has 4 legs, each cat has 4 legs.
 * - Dogs cannot ride on anything.
 * - Cats can ride on dogs (max 2 cats per dog).
 * - If a cat rides on a dog, its legs are not counted.
 */

void solve() {
    long long C, D, L;
    cin >> C >> D >> L;

    // L must be a multiple of 4
    if (L % 4 != 0) {
        cout << "no" << "\n";
        return;
    }

    // Max legs possible: all cats and dogs on the ground
    long long max_legs = (C + D) * 4;

    // Min legs possible:
    // All dogs must be on the ground.
    // Cats can ride on dogs (up to 2 per dog).
    long long cats_on_ground = max(0LL, C - 2 * D);
    long long min_legs = (D + cats_on_ground) * 4;

    // Check if L falls within the valid range
    if (L >= min_legs && L <= max_legs) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```