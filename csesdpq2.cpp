#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0;  // Base case: 0 coins to make sum 0

    for (int i = 1; i <= x; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[x] == INF) cout << -1 << endl;
    else cout << dp[x] << endl;

    return 0;
}
