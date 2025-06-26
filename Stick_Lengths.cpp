#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
    double n,sum=0;
    cin>>n;
    vector<double>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
       
    }
    sort(v.begin(),v.end());
    int x=n/2;

    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        if(x!=0)sum1+=abs(v[i]-v[x-1]);
        sum2+=abs(v[i]-v[x]);
    }
    cout<<min(sum1,sum2)<<endl;
    return 0;
}
    