#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int totalval(int val, vector<int>& total, const vector<int>& coins) {
    if (val == 0) return 1;
    if (total[val] != -1) return total[val];

    int sum = 0;
    for (int x : coins) {
        if (val - x >= 0) {
            sum = (sum + totalval(val - x, total, coins)) % MOD;
        }
    }

    return total[val] = sum;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    vector<int> total(x + 1, -1);
    total[0] = 1;

    cout << totalval(x, total, coins) << endl;
    return 0;
}
