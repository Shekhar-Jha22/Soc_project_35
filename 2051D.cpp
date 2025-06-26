#define ll long long int
#include<bits/stdc++.h>
using namespace std;

int main(){
    ll t;
    cin >>t;
    
    for(ll i=0;i<t;i++){
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ll >v;
        ll sum1=0;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            v.push_back(x);
            sum1+=x;
        }
        sort(v.begin(),v.end());
        ll sum=0;

        for(ll i=0;i<n-1;i++){
            if(upper_bound(v.begin()+i+1,v.end(),sum1-x-v[i])> v.begin()+i && lower_bound(v.begin()+1+i,v.end(),sum1-y-v[i])>v.begin()+i){
                sum+=  (upper_bound(v.begin()+i+1,v.end(),sum1-x-v[i])-lower_bound(v.begin()+1+i,v.end(),sum1-y-v[i]));
            }
            else if(upper_bound(v.begin()+i+1,v.end(),sum1-x-v[i])> v.begin()+i){ 
                sum+=  (upper_bound(v.begin()+i+1,v.end(),sum1-x-v[i])-v.begin()+i);
            }

            

        }
        cout<<sum<<endl;


    }
}