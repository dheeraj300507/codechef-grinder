#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: International Education Day!
 * The problem asks us to calculate the total sales for Chef (A * C) and Chefina (B * C)
 * and output the maximum of the two.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves handling multiple 
    // test cases if specified. Given the constraints and format, we read A, B, and C.
    
    long long A, B, C;
    if (cin >> A >> B >> C) {
        long long chef_sales = A * C;
        long long chefina_sales = B * C;
        
        // Output the maximum of the two sales
        cout << max(chef_sales, chefina_sales) << "\n";
    }

    return 0;
}