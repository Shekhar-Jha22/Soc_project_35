#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<double> x(n), v(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }
    double minx=*min_element(x.begin(),x.end());
    double maxx=*max_element(x.begin(),x.end());
    double l = 0, r = (maxx-minx)/(*min_element(v.begin(),v.end()));
    double ans = r;

    while (r - l >= 1e-6) {
        double mid = (l + r) / 2.0;
        double lx = minx, rx = maxx;

        for (int i = 0; i < n; i++) {
            lx = max(lx, x[i] - v[i] * mid);
            rx = min(rx, x[i] + v[i] * mid);
        }

        if (lx <= rx) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
