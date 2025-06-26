#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long dp(long long x, long long y, vector<vector<long long>>& v, long long n, vector<vector<long long>>& memo) {
    if (x >= n || y >= n) return 0;               // Out of bounds
    if (v[x][y] == 1) return 0;                   // Obstacle
    if (x == n - 1 && y == n - 1) return 1;       // Destination

    if (memo[x][y] != -1) return memo[x][y];

    long long right = dp(x, y + 1, v, n, memo);
    long long down  = dp(x + 1, y, v, n, memo);

    return memo[x][y] = (right + down) % MOD;
}

int main() {
    long long n;
    cin >> n;

    vector<vector<long long>> v(n, vector<long long>(n));
    vector<vector<long long>> memo(n, vector<long long>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            v[i][j] = (c == '.') ? 0 : 1;
        }
    }

    cout << dp(0, 0, v, n, memo) << endl;
}
