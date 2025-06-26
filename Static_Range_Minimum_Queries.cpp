#include<bits/stdc++.h>
using namespace std;
#define int long long 
int power(int n){
    for(int i=0;i<62;i++){
        if((1<<i)>n)return (1<<i);
    }
    return -1;
}

int32_t main(){
    int n,q;
    cin>>n>>q;
    int a=power(n);

    vector<int>v(2*a,INT64_MAX);

    for(int i=a;i<a+n;i++){
        cin>>v[i];
    }
    for(int i=a-1;i>=1;i--){
        v[i]=min(v[2*i],v[2*i+1]);
    }
    auto range_min = [&](int l, int r) {
        l += a;
        r += a;
        int res = INT64_MAX;
        while (l <= r) {
            if (l % 2 == 1) res = min(res, v[l++]);
            if (r % 2 == 0) res = min(res, v[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };

    // Run queries
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << range_min(l-1, r-1) << '\n';
    }

}