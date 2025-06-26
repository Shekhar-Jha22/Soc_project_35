#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<long long> memo(1e6 + 1, -1);  // adjust size as needed

long long dp(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];

    long long res = 0;
    for (int i = 1; i <= 6; ++i) {
        res = (res + dp(n - i)) % MOD;
    }
    return memo[n] = res;
}

int main() {
    int n;
    cin >> n;
    cout << dp(n) << endl;
}
