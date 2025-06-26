#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    double n,l;
    cin>>n>>l;
    vector<double>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    double value=0;
    double l=0,r=*max_element(v.begin(),v.end());
    while(l<=r){
        double mid=(l+r)/2;

        vector<int>temp=v;
        for(int i=0;i<n;i++){
            temp[i]-=mid;
        }
        vector<int>suffix(n+1,0);
        for(int i=1;i<n;i++)suffix[i]=suffix[i-1]+v[i-1];
        vector<int>minimum(n,0);
        for(int i=1;i<n;i++){
            minimum[i]=min(minimum[i-1],suffix[i]);
        }
        for(int i=0;i<n;i++){
            if(suffix[i+1]-minimum[i]>=0){
                l=mid;
                value=max(value,mid);
            }
            else{
                r=mid;
            }
        }
    }

}