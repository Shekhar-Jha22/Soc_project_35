#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,q;
    cin>>n>>q;
    
    vector<int>prefix(n+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        prefix[i+1]=x+prefix[i];
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
    return 0;
}