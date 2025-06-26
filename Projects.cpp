#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Project {
    int l, r, p;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].l >> projects[i].r >> projects[i].p;
    }

    // Sort projects by ending time
    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
        return a.r < b.r;
    });

    map<int, int> dp; // dp[time] = max profit till that time
    dp[0] = 0;

    for (auto &proj : projects) {
        // Get max profit before start time
        auto it = dp.upper_bound(proj.l - 1);
        if (it != dp.begin()) --it;
        int prev_profit = it->second;

        int new_profit = prev_profit + proj.p;
        // If this reward improves answer at proj.r
        if (new_profit > dp.rbegin()->second) {
            dp[proj.r] = new_profit;
        }
    }

    cout << dp.rbegin()->second << '\n';
    return 0;
}
