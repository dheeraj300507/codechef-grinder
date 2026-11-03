# [Naive Chef (NAICHEF)](https://www.codechef.com/problems/NAICHEF)

- **Difficulty Rating**: 990
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a die with $N$ faces, where the values on the faces are provided as an array, we need to calculate the probability that the die shows face $A$ on the first roll and face $B$ on the second roll. Since the two rolls are independent events, the total probability is the product of the individual probabilities of rolling $A$ and $B$.

## Intuition & Mathematical Observation
1. **Probability Calculation**: The probability of an event occurring is defined as the number of favorable outcomes divided by the total number of possible outcomes.
   - Let $count(A)$ be the number of times value $A$ appears in the array.
   - Let $count(B)$ be the number of times value $B$ appears in the array.
   - The probability of rolling $A$ is $P(A) = \frac{count(A)}{N}$.
   - The probability of rolling $B$ is $P(B) = \frac{count(B)}{N}$.
2. **Independence**: Because the two rolls are independent, the joint probability $P(A \text{ and } B) = P(A) \times P(B)$.
3. **Implementation**: We iterate through the array once to count the occurrences of $A$ and $B$, then compute the product. Using `double` for division ensures precision, and `std::fixed` with `std::setprecision` is used to meet the output requirements.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of faces on the die. We traverse the array exactly once to count the occurrences. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the array of faces. (Note: This could be optimized to $O(1)$ by counting $A$ and $B$ on the fly without storing the array).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/**
 * Problem Analysis:
 * The probability of rolling A is (count of A) / N.
 * The probability of rolling B is (count of B) / N.
 * Since the tosses are independent, the probability of both occurring is:
 * ((count of A) / N) * ((count of B) / N)
 * 
 * Constraints:
 * N <= 10^4, T <= 70. An O(N) approach per test case is well within limits.
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;
    
    vector<int> x(N);
    double countA = 0;
    double countB = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        if (x[i] == A) {
            countA++;
        }
        if (x[i] == B) {
            countB++;
        }
    }
    
    double probA = countA / (double)N;
    double probB = countB / (double)N;
    
    // Output the result with required precision
    cout << fixed << setprecision(10) << (probA * probB) << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```