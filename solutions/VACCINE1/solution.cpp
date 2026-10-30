#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the smallest day 'd' such that the total vaccines produced
 * by Company A and Company B is >= P.
 * 
 * Company A starts on day D1 and produces V1 per day.
 * Company B starts on day D2 and produces V2 per day.
 * 
 * Total vaccines on day 'd':
 * If d < D1, A produces 0.
 * If d >= D1, A produces (d - D1 + 1) * V1.
 * If d < D2, B produces 0.
 * If d >= D2, B produces (d - D2 + 1) * V2.
 * 
 * Since the constraints are very small (P <= 1000, D, V <= 100),
 * we can simply iterate day by day starting from 1 until the condition is met.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    long long total_vaccines = 0;
    int day = 0;

    // Simulate day by day
    while (total_vaccines < P) {
        day++;
        if (day >= D1) {
            total_vaccines += V1;
        }
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}