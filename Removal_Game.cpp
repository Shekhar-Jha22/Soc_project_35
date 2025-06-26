#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    vector<long long> prefix(n + 1, 0);

    // Compute prefix sums
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    // Base case: one element
    for (int i = 0; i < n; ++i) {
        dp[i][i] = v[i];
    }

    // Solve for subarrays of increasing length
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            long long total = prefix[j + 1] - prefix[i];
            dp[i][j] = max(v[i] + (total - v[i] - dp[i + 1][j]),
                           v[j] + (total - v[j] - dp[i][j - 1]));
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
