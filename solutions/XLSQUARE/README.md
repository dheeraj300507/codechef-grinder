# [Large Square (XLSQUARE)](https://www.codechef.com/problems/XLSQUARE)

- **Difficulty Rating**: 1160
- **Solved in**: 3 attempt(s)

## Problem Summary
We are given $N$ identical small squares, each with a side length of $A$. We need to arrange as many of these squares as possible into a larger "mega square" configuration. The mega square must be composed of $m \times m$ small squares. We need to find the side length of this largest possible mega square.

## Intuition & Mathematical Observation
To form a mega square of size $m \times m$, we require $m^2$ small squares. Since we have a total of $N$ small squares available, the constraint is:
$$m^2 \le N$$

To maximize the side length of the mega square, we must maximize $m$. Solving for $m$:
$$m \le \sqrt{N}$$
Since $m$ must be an integer, the largest possible value for $m$ is $\lfloor \sqrt{N} \rfloor$.

Once we have the maximum number of squares along one side ($m$), the total side length of the mega square is simply:
$$\text{Side Length} = m \times A$$

**Example:** If $N = 10$ and $A = 2$:
- $\sqrt{10} \approx 3.16$, so $m = 3$.
- Side length = $3 \times 2 = 6$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. The calculation involves a square root operation and a multiplication, both of which are constant time operations.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

/**
 * Problem Analysis:
 * We have N squares of side length A.
 * A mega square of side length S = m * A is composed of m * m small squares.
 * To maximize S, we need to maximize m such that m * m <= N.
 * Thus, m = floor(sqrt(N)).
 * The side length of the mega square is floor(sqrt(N)) * A.
 * 
 * Constraints:
 * N <= 10^5, A <= 10^4.
 * The result can be up to sqrt(10^5) * 10^4 ≈ 316 * 10^4 = 3,160,000.
 * This fits comfortably within a standard 32-bit integer, but using 
 * long long is safer and prevents overflow during intermediate calculations.
 */

using namespace std;

void solve() {
    long long n, a;
    if (!(cin >> n >> a)) return;

    // Calculate the maximum integer m such that m*m <= n
    // Using sqrt is safe for N up to 10^5.
    long long m = static_cast<long long>(sqrt(n));

    // The side length of the mega square is m * A
    long long result = m * a;

    cout << result << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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