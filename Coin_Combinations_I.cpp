#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;

    vector<int>v(x+1,0),coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    v[0]=1;

    for(int i=1;i<=x;i++){
        for(auto c:coins){
            if(i-c>=0)
            v[i]+=v[i-c];
           
        }
        v[i]=v[i]%MOD;
    }
    cout<<v[x]%(int)(1e9+7)<<endl;
    return 0;
}