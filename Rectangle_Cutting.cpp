#include<bits/stdc++.h>
using namespace std;

int minCuts(int a, int b) {
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = INT_MAX;
                // Try horizontal cuts
                for (int k = 1; k < i; ++k)
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                // Try vertical cuts
                for (int k = 1; k < j; ++k)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }
    return dp[a][b];
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<minCuts(a,b)<<endl;
}
