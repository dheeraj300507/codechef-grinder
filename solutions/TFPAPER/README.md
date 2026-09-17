# [True and False Paper (TFPAPER)](https://www.codechef.com/problems/TFPAPER)

- **Difficulty Rating**: 398
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice takes a test consisting of $N$ True/False questions and scores $K$ marks. Bob takes the same test but marks the exact opposite answer for every single question compared to Alice. We need to determine Bob's score on the test.

## Intuition & Mathematical Observation
The key observation lies in the nature of True/False questions:
1. Alice has $N$ total questions.
2. Alice got $K$ questions correct, which implies she got $N - K$ questions incorrect.
3. Since Bob marked the opposite of Alice for every question:
   - If Alice was correct, Bob must be incorrect.
   - If Alice was incorrect, Bob must be correct.
4. Therefore, the number of questions Bob got correct is exactly equal to the number of questions Alice got incorrect.

**Mathematical Formula:**
$$\text{Bob's Score} = N - K$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time subtraction operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has N questions.
 * She scored K marks, meaning she got K questions correct and (N - K) questions incorrect.
 * Bob marked the opposite of Alice for every question.
 * If Alice was correct on a question, Bob is incorrect.
 * If Alice was incorrect on a question, Bob is correct.
 * Therefore, the number of questions Bob got correct is exactly the number of questions 
 * Alice got incorrect, which is (N - K).
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        // Bob's score is the number of questions Alice got wrong
        long long bobs_score = n - k;
        
        cout << bobs_score << "\n";
    }
    
    return 0;
}
```