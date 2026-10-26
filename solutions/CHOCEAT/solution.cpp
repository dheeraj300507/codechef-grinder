#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
        if (A == B) {
            cout << A + B - 1 << "\n";
        } else {
            cout << A + B << "\n";
        }
    }
    return 0;
}