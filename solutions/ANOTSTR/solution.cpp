#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An operation consists of choosing indices i and j, swapping A[i] and A[j],
 * and flipping both.
 * Let's see what happens to the number of 1s in the string:
 * - If we pick (0, 0): they become (1, 1). Number of 1s increases by 2.
 * - If we pick (1, 1): they become (0, 0). Number of 1s decreases by 2.
 * - If we pick (0, 1): they become (0, 1). Number of 1s remains the same.
 * 
 * In all cases, the parity of the number of 1s in the string remains invariant.
 * 
 * Additionally, consider the parity of the positions.
 * Let S_A be the sum of indices (1-based) where A[i] == '1'.
 * When we swap and flip indices i and j:
 * - If A[i]=0, A[j]=0: They become 1 at i and 1 at j. 
 *   New sum = S_A + i + j. Change is (i + j).
 * - If A[i]=1, A[j]=1: They become 0 at i and 0 at j. 
 *   New sum = S_A - i - j. Change is -(i + j).
 * - If A[i]=0, A[j]=1: They become 0 at j and 1 at i.
 *   New sum = S_A - j + i. Change is (i - j).
 * 
 * Notice that in all cases, the change in the sum of indices of 1s is (i+j) or (i-j).
 * Since (i+j) and (i-j) have the same parity as (i+j), the parity of the sum of 
 * indices of 1s changes by (i+j) mod 2.
 * 
 * Actually, there is a simpler invariant. Let's look at the parity of the number of 1s.
 * The operation changes the count of 1s by +2, -2, or 0.
 * Thus, the parity of the number of 1s is invariant.
 * 
 * Is that enough? Let's check sample 3:
 * A = 0110 (indices 2, 3 are 1s. Sum = 5. Count = 2)
 * B = 1000 (index 1 is 1. Sum = 1. Count = 1)
 * Parity of count is different (2 vs 1). Output NO. Correct.
 * 
 * Are there any other invariants?
 * The operation allows us to change the count of 1s by 2.
 * If N >= 3, we can effectively move 1s around and change the count by 2 
 * as long as we have enough space.
 * For N >= 3, the only invariant is the parity of the number of 1s.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA = 0;
    for (char c : A) if (c == '1') countA++;
    
    int countB = 0;
    for (char c : B) if (c == '1') countB++;

    if (countA % 2 == countB % 2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}