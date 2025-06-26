#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));  // 1-based indexing, pad to avoid bounds

    // Initialize base case
    if (v[0] == 0) {
        for (int x = 1; x <= m; ++x)
            dp[0][x] = 1;
    } else {
        dp[0][v[0]] = 1;
    }

    // Fill DP table
    for (int i = 1; i < n; ++i) {
        if (v[i] == 0) {
            for (int x = 1; x <= m; ++x) {
                dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % MOD + dp[i - 1][x + 1]) % MOD;
            }
        } else {
            int x = v[i];
            dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % MOD + dp[i - 1][x + 1]) % MOD;
        }
    }

    // Compute final result
    int result = 0;
    for (int x = 1; x <= m; ++x)
        result = (result + dp[n - 1][x]) % MOD;

    cout << result << endl;
}
