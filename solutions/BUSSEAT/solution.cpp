#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * People enter one by one.
 * Strategy:
 * 1. People prefer to sit in an empty row.
 * 2. If no empty row is available, they sit next to someone.
 * 
 * Let R be the number of rows.
 * If K <= N:
 * Each person takes one row. No one sits next to anyone. Result = 0.
 * 
 * If K > N:
 * The first N people will each take one row (one seat per row).
 * After N people, all N rows are occupied by 1 person each.
 * The remaining (K - N) people must sit in a row that already has 1 person.
 * When a person sits in a row that already has 1 person, both the person 
 * already there and the new person are now "sitting next to somebody".
 * 
 * So, for the (K - N) people who arrive after the first N:
 * Each of them sits next to the person already in that row.
 * This makes the (K - N) new people "sitting next to somebody".
 * Also, the (K - N) people who were already sitting in those rows 
 * now have a neighbor, so they also become "sitting next to somebody".
 * Total = (K - N) + (K - N) = 2 * (K - N).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            cout << 0 << "\n";
        } else {
            // The number of people who end up sitting next to someone is 2 * (K - N)
            cout << 2 * (k - n) << "\n";
        }
    }

    return 0;
}