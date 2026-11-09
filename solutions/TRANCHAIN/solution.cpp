#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Blood donation rules:
 * O -> A, B, AB, O
 * A -> A, AB
 * B -> B, AB
 * AB -> AB
 * 
 * To form the longest chain, we need to consider the compatibility graph.
 * Notice that O can donate to everyone, and everyone can donate to themselves (if we consider a chain of 1).
 * Actually, the problem asks for the maximum number of people in a chain.
 * If we have a set of people, we can arrange them in a chain if there exists a sequence 
 * such that each person can donate to the next.
 * 
 * Let's count the occurrences of each blood type: countO, countA, countB, countAB.
 * - O can donate to A, B, AB, and O.
 * - A can donate to A and AB.
 * - B can donate to B and AB.
 * - AB can only donate to AB.
 * 
 * The optimal strategy is to put all O's first, then all A's (or B's), then all AB's.
 * Specifically, we can have a chain:
 * (All O's) -> (All A's) -> (All AB's)
 * OR
 * (All O's) -> (All B's) -> (All AB's)
 * 
 * Because O can donate to A, A can donate to AB, and AB can donate to AB.
 * Similarly for B.
 * 
 * Thus, the maximum chain length is max(countO + countA + countAB, countO + countB + countAB).
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