#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to check if there exists a contiguous substring of vowels with length > 2.
 * This is equivalent to checking if there are 3 or more consecutive vowels in the string.
 * 
 * Algorithm:
 * 1. Iterate through the string.
 * 2. Maintain a counter for consecutive vowels.
 * 3. If the current character is a vowel, increment the counter.
 * 4. If the current character is not a vowel, reset the counter to 0.
 * 5. If the counter reaches 3 at any point, the string is "Happy".
 * 6. If the loop finishes without the counter reaching 3, the string is "Sad".
 */

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve() {
    string s;
    cin >> s;
    
    int consecutive_vowels = 0;
    bool happy = false;
    
    for (char c : s) {
        if (isVowel(c)) {
            consecutive_vowels++;
            if (consecutive_vowels > 2) {
                happy = true;
                break;
            }
        } else {
            consecutive_vowels = 0;
        }
    }
    
    if (happy) {
        cout << "Happy" << "\n";
    } else {
        cout << "Sad" << "\n";
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