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
 * 
 * Complexity:
 * Time: O(T * (N + K * L * log(TotalWordsInPhrases)))
 * Space: O(TotalWordsInPhrases)
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