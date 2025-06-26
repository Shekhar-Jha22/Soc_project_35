#include<bits/stdc++.h>
using namespace std;
#define int long long


const int MOD = 1e9 + 7;

// Modular inverse of 2 modulo MOD
const int INV_2 = 500000004;

int32_t main() {
    int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = total / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout << (dp[target] * INV_2) % MOD << endl;
    return 0;
}
