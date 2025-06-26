#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    for (int i = 0; i < n; ++i) cin >> pages[i];

    vector<int> dp(p + 1, 0);  // dp[j] = max pages with budget j

    for (int i = 0; i < n; ++i) {
        for (int j = p; j >= prices[i]; --j) {
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }

    cout << dp[p] << endl;
}
