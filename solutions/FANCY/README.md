# [Fancy Quotes (FANCY)](https://www.codechef.com/problems/FANCY)

- **Difficulty Rating**: 1279
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given sentence contains the word "not" as a standalone word. A sentence is considered "Real Fancy" if the word "not" appears as an independent word (i.e., not part of a larger word like "nothing"). Otherwise, it is "regularly fancy".

## Intuition & Mathematical Observation
To identify if "not" exists as a standalone word, we need to ensure it is delimited by spaces or the boundaries of the string. 

While one could use string searching (checking for "not " at the start, " not " in the middle, or " not" at the end), the most robust and clean approach in C++ is to use `std::stringstream`. By extracting the sentence into individual words using the stream extraction operator (`>>`), we automatically handle whitespace delimiters. We then simply iterate through these tokens and check if any token is exactly equal to the string `"not"`.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the total number of characters in the string. We traverse the string once to extract words and perform a constant-time comparison for each word.
- **Space Complexity**: $O(N)$ to store the input string and the extracted words.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if the word "not" exists as a standalone word in a given string S.
 * Using stringstream is an efficient way to extract words and check for equality with "not".
 */

void solve() {
    string s;
    getline(cin, s);
    
    stringstream ss(s);
    string word;
    bool found = false;
    
    // Extract words one by one using whitespace as the delimiter
    while (ss >> word) {
        if (word == "not") {
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "Real Fancy" << "\n";
    } else {
        cout << "regularly fancy" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    
    // Consume the newline character left after reading t
    string dummy;
    getline(cin, dummy);
    
    while (t--) {
        solve();
    }
    
    return 0;
}
```