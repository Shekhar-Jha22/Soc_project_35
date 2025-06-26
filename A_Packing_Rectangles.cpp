#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,w,h;
    cin>>w>>h>>n;

    int x=max(n*min(w,h),max(w,h));

    int l=0,r=x;

    while(l<r){
        int mid=(l+r)/2;

        if((mid/w)*(mid/h)>=n){
            x=min(mid,x);
            r=mid;
        }
        else{
            l=mid;
        }

        if(l+1==r)break;
    }
    cout<<x<<endl;
    return 0;
}