# [Transfusion Chain (TRANCHAIN)](https://www.codechef.com/problems/TRANCHAIN)

- **Difficulty Rating**: 1214
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a list of blood types for $N$ people. We need to form the longest possible chain of blood donations such that each person in the chain can donate blood to the next person in the sequence. The rules for blood donation are:
- **O** can donate to **O, A, B, AB**.
- **A** can donate to **A, AB**.
- **B** can donate to **B, AB**.
- **AB** can donate to **AB**.

## Intuition & Mathematical Observation
To maximize the chain length, we must observe the compatibility constraints:
1. **O** is a universal donor; it can be placed at the start of any chain.
2. **AB** is a universal recipient; it can be placed at the end of any chain.
3. **A** and **B** are mutually exclusive in a single chain because **A** cannot donate to **B**, and **B** cannot donate to **A**.

Therefore, we have two primary paths to construct the longest chain:
- **Path 1**: All **O**s $\to$ All **A**s $\to$ All **AB**s.
- **Path 2**: All **O**s $\to$ All **B**s $\to$ All **AB**s.

The maximum number of people we can include in a valid chain is simply the maximum of these two paths:
$$\text{Result} = \max(\text{countO} + \text{countA} + \text{countAB}, \text{countO} + \text{countB} + \text{countAB})$$

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of people. We iterate through the list of blood types exactly once to count the occurrences of each type.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the longest chain, we notice that O can donate to everyone, 
 * and AB can receive from everyone. However, A and B cannot donate to each other.
 * Thus, we either include all A's or all B's in our chain along with all O's and AB's.
 */

void solve() {
    int N;
    cin >> N;
    
    int countO = 0, countA = 0, countB = 0, countAB = 0;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (s == "O") countO++;
        else if (s == "A") countA++;
        else if (s == "B") countB++;
        else if (s == "AB") countAB++;
    }
    
    // Chain 1: O -> A -> AB
    int chain1 = countO + countA + countAB;
    // Chain 2: O -> B -> AB
    int chain2 = countO + countB + countAB;
    
    cout << max(chain1, chain2) << "\n";
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