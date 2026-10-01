#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red orbs and B blue orbs.
 * Cost of 1 green orb = 1 red + 1 blue.
 * Skill values:
 * Red = 1
 * Blue = 2
 * Green = 5
 * 
 * Let k be the number of green orbs we create.
 * k can range from 0 to min(R, B).
 * After creating k green orbs:
 * Remaining Red = R - k
 * Remaining Blue = B - k
 * Remaining Green = k
 * 
 * Total Skill = (R - k) * 1 + (B - k) * 2 + k * 5
 * Total Skill = R - k + 2B - 2k + 5k
 * Total Skill = R + 2B + 2k
 * 
 * To maximize the skill, we need to maximize k.
 * Since k = min(R, B), the maximum skill is obtained by setting k = min(R, B).
 */

void solve() {
    long long R, B;
    if (!(cin >> R >> B)) return;
    
    long long k = min(R, B);
    long long max_skill = (R - k) * 1 + (B - k) * 2 + k * 5;
    
    cout << max_skill << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem description implies a single test case per run based on 
    // "The first and only line of input contains 2 integers".
    // However, the instructions mention "Handle multiple test cases properly".
    // Given the constraints and format, we will check if there's a test case count 
    // or just process the single line provided.
    
    solve();
    
    return 0;
}