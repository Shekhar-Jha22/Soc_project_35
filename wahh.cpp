#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(int n, const vector<pair<int, int>>& obs, vector<int>& d) {
    vector<int> lo(n+1), hi(n+1);
    lo[0] = hi[0] = 0;

    // Forward pass: track valid height ranges at each point
    for (int i = 1; i <= n; ++i) {
        if (d[i-1] == 0) {
            lo[i] = lo[i-1];
            hi[i] = hi[i-1];
        } else if (d[i-1] == 1) {
            lo[i] = lo[i-1] + 1;
            hi[i] = hi[i-1] + 1;
        } else {
            lo[i] = lo[i-1];
            hi[i] = hi[i-1] + 1;
        }

        // Apply obstacle bounds
        lo[i] = max(lo[i], obs[i-1].first);
        hi[i] = min(hi[i], obs[i-1].second);

        if (lo[i] > hi[i]) return false;  // no possible height
    }

    // Backtrack to reconstruct path
    int h = lo[n];
    for (int i = n-1; i >= 0; --i) {
        int prev0 = h;
        int prev1 = h - 1;

        if (d[i] != -1) {
            h = (d[i] == 0 ? prev0 : prev1);
        } else {
            if (prev1 >= lo[i] && prev1 <= hi[i]) {
                d[i] = 1;
                h = prev1;
            } else if (prev0 >= lo[i] && prev0 <= hi[i]) {
                d[i] = 0;
                h = prev0;
            } else {
                return false; // impossible to backtrack
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<pair<int, int>> obs(n);
        for (int i = 0; i < n; ++i) {
            cin >> obs[i].first >> obs[i].second;
        }

        vector<int> d(n);
        for (int i = 0; i < n; ++i) cin >> d[i];

        if (solve(n, obs, d)) {
            cout << "YES\n";
            for (int i : d) cout << i << " ";
            cout << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}
