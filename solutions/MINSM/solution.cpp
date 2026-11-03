#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows replacing A_i or A_j with gcd(A_i, A_j).
 * By repeatedly applying this, we can eventually make every element in the array
 * equal to the greatest common divisor of all elements in the array, let's call it G.
 * 
 * However, we want to minimize the sum. If we have the whole array, we can find
 * the GCD of all elements, say G = gcd(A_1, A_2, ..., A_N).
 * We can replace every element with G, resulting in a sum of N * G.
 * 
 * But we can do better. If we pick two elements A_i and A_j, we can replace one
 * with gcd(A_i, A_j). If we have a set of numbers, the best we can do is to 
 * reduce all numbers to the GCD of the entire array.
 * 
 * Wait, let's re-examine: If we have elements, we can replace any A_i with gcd(A_i, A_j).
 * This means we can make all elements equal to the GCD of the entire array.
 * Is it possible to have a smaller sum?
 * Actually, if we have the GCD of the entire array, say G, we can replace all 
 * elements with G. The sum would be N * G.
 * 
 * Can we keep some elements as they are?
 * If we have A_1, A_2, ..., A_N, let G = gcd(A_1, A_2, ..., A_N).
 * We can replace all A_i with G. The sum is N * G.
 * Is it possible to have a sum smaller than N * G?
 * No, because every element in the array must be a multiple of the GCD of the 
 * final array. Since the GCD of the final array must be a multiple of the 
 * original GCD (G), every element must be at least G. Thus the sum is at least N * G.
 * 
 * Wait, the sample cases:
 * 5 10 -> gcd is 5. Sum = 5 + 5 = 10. (N=2, G=5, N*G=10). Correct.
 * 2 2 6 -> gcd is 2. Sum = 2 + 2 + 2 = 6. (N=3, G=2, N*G=6). Correct.
 * 
 * The logic holds: The minimum sum is N * gcd(A_1, A_2, ..., A_N).
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long g = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i == 0) g = A[i];
        else g = gcd(g, A[i]);
    }
    
    cout << (long long)N * g << "\n";
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