# [Mileage matters (MILEAGE)](https://www.codechef.com/problems/MILEAGE)

- **Difficulty Rating**: 831
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given the distance to travel ($N$), the price of petrol ($X$) and diesel ($Y$), and the mileage of the vehicle using petrol ($A$ km/l) and diesel ($B$ km/l). You need to determine which fuel is cheaper for the given distance. If both cost the same, output "ANY".

## Intuition & Mathematical Observation
To find the cost of fuel, we calculate:
- **Cost of Petrol**: $\text{Cost}_P = \frac{N}{A} \times X$
- **Cost of Diesel**: $\text{Cost}_D = \frac{N}{B} \times Y$

We need to compare $\frac{N \cdot X}{A}$ and $\frac{N \cdot Y}{B}$. 

While floating-point division works for the given constraints ($N, X, Y, A, B \le 100$), a more robust approach is to avoid division by cross-multiplying:
1. Compare $(N \cdot X \cdot B)$ with $(N \cdot Y \cdot A)$.
2. Since $N$ is always positive, we can simplify this to comparing $(X \cdot B)$ and $(Y \cdot A)$.

Using `double` with a small epsilon ($\epsilon$) is also perfectly acceptable here given the small input range, as shown in the provided solution.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Distance to travel: N
 * Petrol: Price X, Mileage A km/litre.
 * Cost of petrol = (N / A) * X.
 * 
 * Diesel: Price Y, Mileage B km/litre.
 * Cost of diesel = (N / B) * Y.
 */

void solve() {
    double N, X, Y, A, B;
    if (!(cin >> N >> X >> Y >> A >> B)) return;

    // Calculate costs
    double cost_petrol = (N / A) * X;
    double cost_diesel = (N / B) * Y;

    // Compare costs using a small epsilon for floating point precision
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
```