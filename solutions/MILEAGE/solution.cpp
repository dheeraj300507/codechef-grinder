#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Distance to travel: N
 * Petrol: Price X, Mileage A km/litre.
 * Amount of petrol needed = N / A litres.
 * Cost of petrol = (N / A) * X.
 * 
 * Diesel: Price Y, Mileage B km/litre.
 * Amount of diesel needed = N / B litres.
 * Cost of diesel = (N / B) * Y.
 * 
 * To compare (N * X) / A and (N * Y) / B:
 * We can multiply both sides by (A * B) to avoid floating point precision issues:
 * Cost_Petrol_Scaled = N * X * B
 * Cost_Diesel_Scaled = N * Y * A
 * 
 * Since N > 0, we can compare (X * B) and (Y * A).
 */

void solve() {
    long long N, X, Y, A, B;
    if (!(cin >> N >> X >> Y >> A >> B)) return;

    // Using double for direct calculation is safe given constraints (100),
    // but cross-multiplication with long long is robust.
    double cost_petrol = (double)N * X / A;
    double cost_diesel = (double)N * Y / B;

    // Use a small epsilon for floating point comparison, 
    // though with these constraints, direct comparison is usually fine.
    if (abs(cost_petrol - cost_diesel) < 1e-9) {
        cout << "ANY" << "\n";
    } else if (cost_petrol < cost_diesel) {
        cout << "PETROL" << "\n";
    } else {
        cout << "DIESEL" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}