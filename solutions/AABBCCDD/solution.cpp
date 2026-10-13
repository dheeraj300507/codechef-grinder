#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1 allows us to convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as its lowercase 
 *    counterpart 'x' for the purpose of counting potential occurrences.
 * 2. Operation 2 allows us to pick one lowercase letter and merge all its occurrences 
 *    into another lowercase letter.
 * 3. Goal: Maximize the count of a single lowercase letter.
 * 
 * Strategy:
 * - First, convert all uppercase letters to lowercase. Now we have a string of only 
 *   lowercase letters.
 * - Let 'count[c]' be the frequency of character 'c' in this modified string.
 * - We can choose one character 'x' and merge it into another character 'y'.
 * - The new frequency of 'y' will be count[y] + count[x].
 * - To maximize this, we should pick the two characters with the highest frequencies 
 *   in the string and merge them.
 * - If there is only one unique character, the score is just its frequency.
 * - If there are multiple, the max score is the sum of the two largest frequencies.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> freq(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else {
            freq[c - 'a']++;
        }
    }

    // Sort frequencies to find the two largest
    sort(freq.rbegin(), freq.rend());

    // The maximum score is the sum of the two most frequent characters.
    // Even if we don't perform operation 2, the result is freq[0] + freq[1] 
    // (where freq[1] could be 0 if only one character type exists).
    cout << freq[0] + freq[1] << "\n";
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