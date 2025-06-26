#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<double>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];

    sort(v.begin(),v.end());
    double l=0,r=v.back();
    double  eps=1e-9;
    double length=0;
    while(r-l>eps){
        double mid=(l+r)/2;

        int sum=0;
        for(int i=0;i<n;i++)sum+=v[i]/mid;

        if(sum>=k){
            length=max(length,mid);
            l=mid;
        }
        else r=mid;
    }
    cout << fixed << setprecision(10) << length << endl;

    return 0;
}