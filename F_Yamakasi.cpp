#include <bits/stdc++.h>
using namespace std;
#define int long long

class segtree {
    vector<int> tree;
    int size;

public:
    segtree(const vector<int>& a) {
        int n = a.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, LLONG_MIN);
        for (int i = 0; i < n; ++i)
            tree[size + i] = a[i];
        for (int i = size - 1; i > 0; --i)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    int query(int l, int r) {
        l += size;
        r += size;
        int res = LLONG_MIN;
        while (l <= r) {
            if (l % 2 == 1) res = max(res, tree[l++]);
            if (r % 2 == 0) res = max(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, s, x;
        cin >> n >> s >> x;
        vector<int> v(n);
        for (int& val : v) cin >> val;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + v[i];

        map<int, vector<int>> pref_index;
        pref_index[0].push_back(-1); // base case: sum 0 before start

        segtree st(v);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int curr_sum = prefix[i + 1];
            int target = curr_sum - s;
            if (pref_index.count(target)) {
                for (int start : pref_index[target]) {
                    int l = start + 1;
                    int r = i;
                    if (l <= r && st.query(l, r) == x) {
                        count++;
                    }
                }
            }
            pref_index[curr_sum].push_back(i);
        }
        cout << count << "\n";
    }

    return 0;
}
