#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int k,n;
    cin>>k>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int total=0,l=0,r=50e9;

    while(l<=r){
        int mid=(l+r)/2;
        int sum=0;
        for(int i=0;i<n;i++)sum+=min(mid,v[i]);

        if(sum>=k*mid){
            total=max(total,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<total<<endl;
    return 0;
}