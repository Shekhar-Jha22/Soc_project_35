#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];

    sort(v.begin(),v.end());

    if(v[0]!=1){
        cout<<1<<endl;
        return 0;
    }
    else{
        int max=v[0];
        for(int i=1;i<n;i++){
            if(v[i]>max+1){
                cout<<max+1<<endl;
                return 0;
            }
            else max+=v[i];
        }
        cout<<max+1<<endl;
    }
    return 0;
}