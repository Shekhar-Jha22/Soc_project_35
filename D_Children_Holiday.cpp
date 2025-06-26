#include <bits/stdc++.h>
using namespace std;

#define int long long

struct triple {
    int t, z, y;
};

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<triple> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].t >> v[i].z >> v[i].y;
    }

    int l = 0, r = 1e9, mintime = r;

    // Binary search for minimum time
    while (l <= r) {
        int mid = (l + r) / 2;
        int total = 0;

        for (int i = 0; i < m; i++) {
            int cycle = v[i].t * v[i].z + v[i].y;
            int full = mid / cycle;
            int rem = mid % cycle;
            int extra = min(rem / v[i].t, v[i].z);
            total += full * v[i].z + extra;
        }

        if (total >= n) {
            mintime = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << mintime << "\n";

    // Determine exact output per machine
    int remaining = n;
    for (int i = 0; i < m; i++) {
        int cycle = v[i].t * v[i].z + v[i].y;
        int full = mintime / cycle;
        int rem = mintime % cycle;
        int extra = min(rem / v[i].t, v[i].z);
        int total = full * v[i].z + extra;

        int give = min(total, remaining);
        cout << give << " ";
        remaining -= give;
    }

    cout << endl;
    return 0;
}

    