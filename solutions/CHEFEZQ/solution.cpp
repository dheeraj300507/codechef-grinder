#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef receives Q_i queries on day i. He can answer at most k queries per day.
 * Let S_i be the number of queries carried over to day i.
 * S_1 = 0
 * On day i, total queries available = S_i + Q_i.
 * If (S_i + Q_i) < k, Chef answers all (S_i + Q_i) queries and is free on day i.
 * Otherwise, he answers k queries and carries over (S_i + Q_i - k) to day i+1.
 * 
 * We need to find the first day i where he answers < k queries.
 * If he finishes all n days and still has queries, he will continue answering k queries
 * until he runs out.
 */

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<long long> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    
    long long carry = 0;
    for (int i = 0; i < n; ++i) {
        long long total = carry + q[i];
        if (total < k) {
            cout << i + 1 << "\n";
            return;
        }
        carry = total - k;
    }
    
    // If we reach here, Chef still has 'carry' queries left after day n.
    // He answers k queries per day until he is done.
    // The number of additional days required is ceil(carry / k).
    // The day he finishes is n + ceil(carry / k).
    // ceil(a/b) = (a + b - 1) / b using integer division.
    
    long long additional_days = (carry + k) / k;
    cout << n + additional_days << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}