#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    string s;
    cin >> s;

    int bread = 0, cheese = 0, sausage = 0;
    for (char ch : s) {
        if (ch == 'B') bread++;
        else if (ch == 'C') cheese++;
        else if (ch == 'S') sausage++;
    }

    int bcurr, scurr, ccurr;
    cin >> bcurr >> scurr >> ccurr;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    int money;
    cin >> money;

    auto can_make = [&](int cnt) {
        int need_b = max(0LL, bread * cnt - bcurr);
        int need_s = max(0LL, sausage * cnt - scurr);
        int need_c = max(0LL, cheese * cnt - ccurr);
        int cost = need_b * pb + need_s * ps + need_c * pc;
        return cost <= money;
    };

    int l = 0, r = 1e13, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (can_make(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
