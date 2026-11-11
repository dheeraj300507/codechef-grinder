# [Truth and Dare (TRUEDARE)](https://www.codechef.com/problems/TRUEDARE)

- **Difficulty Rating**: 1231
- **Solved in**: 1 attempt(s)

## Problem Summary
Ram and Shyam are playing a game of Truth and Dare. Ram has a set of truth tasks he can perform and a set of dare tasks he can perform. Shyam challenges Ram with a specific list of truth tasks and a specific list of dare tasks. Ram wins the game if and only if he can perform **all** the truth tasks Shyam asks for **and** all the dare tasks Shyam asks for. Otherwise, Shyam wins.

## Intuition & Mathematical Observation
The problem asks us to verify if two subsets are contained within two other sets:
1. Let $T_R$ be the set of truth tasks Ram can perform and $D_R$ be the set of dare tasks Ram can perform.
2. Let $T_S$ be the set of truth tasks Shyam demands and $D_S$ be the set of dare tasks Shyam demands.

Ram wins if:
- $T_S \subseteq T_R$
- $D_S \subseteq D_R$

Since the constraints are small (up to 100 elements per set), we can store Ram's tasks in a `std::set` or a boolean array for $O(1)$ or $O(\log N)$ lookup. We then iterate through each task in Shyam's lists and check if they exist in Ram's corresponding sets. If any task is missing, Ram cannot fulfill the requirement, and we output "no". If all tasks are found, we output "yes".

## Complexity Analysis
- **Time Complexity**: $O(T \times (N + M))$, where $T$ is the number of test cases, $N$ is the total number of tasks Ram has, and $M$ is the total number of tasks Shyam demands. Using `std::set`, the complexity is $O(T \times (N \log N + M \log N))$. Given the constraints ($N, M \le 100$), this is well within the time limit.
- **Space Complexity**: $O(N)$, as we store Ram's tasks in sets to perform the lookups.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ram wins if and only if every truth task Shyam asks is present in Ram's truth tasks
 * AND every dare task Shyam asks is present in Ram's dare tasks.
 * 
 * Since the constraints are small (up to 100), we can use a boolean array or a set
 * to store Ram's tasks and check if all of Shyam's tasks exist in those sets.
 */

void solve() {
    int tr;
    cin >> tr;
    set<int> ram_truth;
    for (int i = 0; i < tr; ++i) {
        int val;
        cin >> val;
        ram_truth.insert(val);
    }

    int dr;
    cin >> dr;
    set<int> ram_dare;
    for (int i = 0; i < dr; ++i) {
        int val;
        cin >> val;
        ram_dare.insert(val);
    }

    int ts;
    cin >> ts;
    vector<int> shyam_truth(ts);
    for (int i = 0; i < ts; ++i) {
        cin >> shyam_truth[i];
    }

    int ds;
    cin >> ds;
    vector<int> shyam_dare(ds);
    for (int i = 0; i < ds; ++i) {
        cin >> shyam_dare[i];
    }

    bool ram_wins = true;

    // Check if all of Shyam's truth tasks are in Ram's truth tasks
    for (int task : shyam_truth) {
        if (ram_truth.find(task) == ram_truth.end()) {
            ram_wins = false;
            break;
        }
    }

    // Check if all of Shyam's dare tasks are in Ram's dare tasks
    if (ram_wins) {
        for (int task : shyam_dare) {
            if (ram_dare.find(task) == ram_dare.end()) {
                ram_wins = false;
                break;
            }
        }
    }

    if (ram_wins) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```