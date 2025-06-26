#include<bits/stdc++.h>
using namespace std;


int main() {
    string a, b;
    cin >> a >> b;
    int l1 = a.size(), l2 = b.size();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= l1; i++) dp[i][0] = i;
    for (int j = 0; j <= l2; j++) dp[0][j] = j;

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
    }

    cout << dp[l1][l2] << "\n";
}
