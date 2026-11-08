#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a string S of length N such that:
 * 1. S > A (lexicographically)
 * 2. reverse(S) > A (lexicographically)
 * 
 * Strategy:
 * If we set S[0] = 'z', then S will be lexicographically larger than A 
 * (unless A[0] is 'z', but even then, if we set S[0] = 'z', we can manipulate 
 * other characters).
 * 
 * Let's try to construct S such that S[0] = 'z'.
 * If S[0] = 'z', then S is definitely >= A. If A[0] < 'z', S > A is satisfied.
 * If A[0] == 'z', we need to check further.
 * 
 * Actually, a very simple construction:
 * If we set S[0] = 'z', then S is lexicographically largest possible.
 * If we set S[N-1] = 'z', then reverse(S) is lexicographically largest possible.
 * 
 * Let's try S = "z...z".
 * If S = "z...z", then S > A is true unless A is "zz...z".
 * If A is "zz...z", then S = A, which is not strictly larger.
 * 
 * If A is all 'z's, no string of length N can be strictly larger than A.
 * So if A == "zz...z", output -1.
 * Otherwise, "z" repeated N times is a candidate, but we need to ensure 
 * reverse(S) > A. If S = "zz...z", reverse(S) = "zz...z".
 * If A is not "zz...z", then "zz...z" > A and "zz...z" > reverse(A) is not 
 * necessarily true, but "zz...z" > A is true.
 * Wait, the condition is reverse(S) > A.
 * 
 * Let S = "z" + string(N-2, 'a') + "z".
 * If N=1: If A="z", -1. Else "z".
 * If N>1: S = "z" + ... + "z".
 * S starts with 'z', so S > A (unless A starts with 'z').
 * S ends with 'z', so reverse(S) starts with 'z', so reverse(S) > A (unless A starts with 'z').
 * 
 * If A[0] != 'z' and A[N-1] != 'z', "z...z" works.
 * If A[0] == 'z' or A[N-1] == 'z', we need to be careful.
 * Actually, if we just pick S = "z" + string(N-1, 'z'), this is only invalid if A is "zz...z".
 * If A is not "zz...z", then "zz...z" is lexicographically larger than A.
 * And reverse("zz...z") is "zz...z", which is also larger than A.
 * 
 * Conclusion: If A consists of all 'z's, output -1. Otherwise, output "z" repeated N times.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    bool all_z = true;
    for (char c : A) {
        if (c != 'z') {
            all_z = false;
            break;
        }
    }

    if (all_z) {
        cout << -1 << "\n";
    } else {
        string S = "";
        for (int i = 0; i < N; ++i) {
            S += 'z';
        }
        cout << S << "\n";
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