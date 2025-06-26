#include <bits/stdc++.h>
using namespace std;
#define int long long

struct triple {
    int sum;     // Total sum of the segment
    int prefix;  // Max prefix sum
    int suffix;  // Max suffix sum
    int best;    // Max subarray sum
};

class segtree {
    int n, size;
    vector<triple> v;

    triple merge(const triple &left, const triple &right) {
        triple res;
        res.sum = left.sum + right.sum;
        res.prefix = max(left.prefix, left.sum + right.prefix);
        res.suffix = max(right.suffix, right.sum + left.suffix);
        res.best = max({left.best, right.best, left.suffix + right.prefix});
        return res;
    }

public:
    segtree(const vector<int>& arr) {
        n = arr.size();
        int i = 0;
        while ((1LL << i) < n) i++;
        size = (1LL << i);
        v.assign(2 * size, {INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN}); 

       
        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            v[size + i] = {val, val, val, val};
        }

        
        for (int i = size - 1; i >= 1; --i) {
            v[i] = merge(v[2 * i], v[2 * i + 1]);
        }
    }


    void update(int ind, int val) {
        int k = size + ind;
        v[k] = {val, val, val, val};

        for (k /= 2; k >= 1; k /= 2) {
            v[k] = merge(v[2 * k], v[2 * k + 1]);
        }
    }

    triple query(int ql, int qr, int k, int l, int r) {
        if (qr < l || r < ql) return {INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN};
        if (ql <= l && r <= qr) return v[k];

        int mid = (l + r) / 2;
        triple left = query(ql, qr, 2 * k, l, mid);
        triple right = query(ql, qr, 2 * k + 1, mid + 1, r);
        return merge(left, right);
    }

    int maxsum(int l, int r) {
        return query(l, r, 1, 0, size - 1).best;
    }
};

int32_t main(){
    int n,m;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];

    segtree st(v);
    cout<<st.maxsum(0,n-1)<<endl;
    
}