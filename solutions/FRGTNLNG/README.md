# [Forgotten Language (FRGTNLNG)](https://www.codechef.com/problems/FRGTNLNG)

- **Difficulty Rating**: 1329
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given a list of $N$ "forgotten" words that belong to an ancient language. We are also provided with $K$ phrases, where each phrase contains a certain number of words currently in use. Our goal is to determine, for each of the $N$ forgotten words, whether it appears in at least one of the $K$ modern phrases. If a word appears, we output "YES"; otherwise, we output "NO".

## Intuition & Mathematical Observation
Since the constraints are quite small ($N, K, L \le 100$), we can efficiently process the input using a hash-based or tree-based lookup structure:

1.  **Storage**: We store all the words found in the $K$ phrases into a `std::set<string>`. A `set` is ideal here because it handles duplicates automatically and provides $O(\log M)$ lookup time, where $M$ is the total number of words in all phrases.
2.  **Verification**: After populating the set with all modern words, we iterate through the original list of $N$ forgotten words. For each word, we perform a lookup in our `set`.
3.  **Efficiency**: Because the total number of words is small, the overhead of `std::set` is negligible, and the logic remains clean and readable.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N + M \log M))$, where $T$ is the number of test cases, $N$ is the number of dictionary words, and $M$ is the total number of words across all phrases. Given the constraints, this comfortably fits within the time limit.
- **Space Complexity**: $O(M)$, as we store all words from the phrases in a `std::set`.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * Problem Analysis:
 * We need to check if each of the N dictionary words appears in any of the K phrases.
 * Given the small constraints (N, K, L <= 100), we can store all words from the 
 * phrases into a set and then check each dictionary word.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    vector<string> dictionary(N);
    for (int i = 0; i < N; ++i) {
        cin >> dictionary[i];
    }

    set<string> modern_words;
    for (int i = 0; i < K; ++i) {
        int L;
        cin >> L;
        for (int j = 0; j < L; ++j) {
            string word;
            cin >> word;
            modern_words.insert(word);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (modern_words.count(dictionary[i])) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```