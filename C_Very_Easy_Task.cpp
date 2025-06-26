#include<bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main(){
    int n,x,y;
    cin>>n>>x>>y;
    int t1=min(x,y);


    int l=0,r=n*t1;
    int mintime=INT32_MAX;
    while(l<=r){
        int mid=(l+r)/2;

        if(mid/x+mid/y>=n-1){
            mintime=min(mintime,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<mintime+t1<<endl;
}