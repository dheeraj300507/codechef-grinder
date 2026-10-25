#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation S[i] = max(S[i], S[i+1]) allows a '1' to propagate to the left.
 * If we have a '1' at index j, we can move it to any index i < j using (j - i) operations.
 * Effectively, if there is at least one '1' in the string, we can make all positions 
 * to the left of the rightmost '1' equal to '1' using the available operations.
 * 
 * Specifically, if we have a '1' at index 'idx', we can use operations to turn 
 * S[idx-1], S[idx-2], ..., S[0] into '1's.
 * Each operation S[i] = max(S[i], S[i+1]) consumes 1 unit of K.
 * To turn a '0' at index i into a '1' using a '1' at index j (where j > i), 
 * we need (j - i) operations.
 * 
 * Given N is very small (N <= 10), we can use a Breadth-First Search (BFS) 
 * or simply observe that we want to maximize the count of '1's.
 * Since N is small, we can treat the string as a state and perform a BFS 
 * to find the maximum number of '1's reachable within K operations.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // State: string S, operations used k
    // Since N is small (up to 10), 2^10 = 1024 states.
    // We can use BFS to find the max ones.
    
    queue<pair<string, int>> q;
    q.push({S, 0});
    
    set<pair<string, int>> visited;
    visited.insert({S, 0});
    
    int max_ones = 0;
    for (char c : S) if (c == '1') max_ones++;
    
    while (!q.empty()) {
        pair<string, int> curr = q.front();
        q.pop();
        
        string s = curr.first;
        int k = curr.second;
        
        int current_ones = 0;
        for (char c : s) if (c == '1') current_ones++;
        max_ones = max(max_ones, current_ones);
        
        if (k < K) {
            for (int i = 0; i < N - 1; ++i) {
                if (s[i] == '0' && s[i+1] == '1') {
                    string next_s = s;
                    next_s[i] = '1';
                    if (visited.find({next_s, k + 1}) == visited.end()) {
                        visited.insert({next_s, k + 1});
                        q.push({next_s, k + 1});
                    }
                }
            }
        }
    }
    cout << max_ones << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}