#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees each.
 * Chef sold M trees for B rupees each.
 * Total Cost = N * A
 * Total Revenue = M * B
 * Profit = (M * B) - (N * A)
 * 
 * The input format is a single line with 4 integers.
 * No test case loop is required.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, A, M, B;
    
    // Read the single line of input
    if (cin >> N >> A >> M >> B) {
        // Calculate total cost and total revenue
        // Constraints: N, M <= 100; A, B <= 1000
        // Max value is 100 * 1000 = 100,000, which fits in int,
        // but long long is safe practice.
        long long total_cost = N * A;
        long long total_revenue = M * B;
        
        long long profit = total_revenue - total_cost;
        
        cout << profit << endl;
    }

    return 0;
}