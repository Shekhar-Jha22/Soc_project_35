#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    vector<vector<char>> dp1(n, vector<char>());
    vector<vector<char>> dp2(n, vector<char>());

    dp1[0].push_back(grid[0][0]);

    for (int i = 1; i < n; ++i) {
        dp1[i] = dp1[i - 1];
        dp1[i].push_back(grid[i][0]);
    }

    

    for (int i = 1; i < n; ++i) {
        dp2[0]=dp1[0];
        dp2[0].push_back(grid[0][i]);
        for (int j = 1; j < n; ++j) {
            if (dp1[j] < dp2[j - 1]) {
                dp2[j] = dp1[j];
            } else {
                dp2[j] = dp2[j - 1];
            }
            dp2[j].push_back(grid[i][j]);
        }
        dp1=dp2;
        int rows = n;
        auto dp2 = new vector<vector<int>>(rows);  // each row is an empty vector<int>

    }

    for (char c : dp1[n - 1]) cout << c;
    cout << '\n';
}
