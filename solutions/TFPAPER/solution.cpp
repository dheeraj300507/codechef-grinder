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
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Optimize standard I/O operations
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