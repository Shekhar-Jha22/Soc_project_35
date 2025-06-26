#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    vector<int>temp;
    for(int i=0;i<n;i++)cin>>v[i];

    temp.push_back(v[0]);

    for(int i=1;i<v.size();i++){
        auto it=lower_bound(temp.begin(),temp.end(),v[i]);

        if(it==temp.end())temp.push_back(v[i]);
        else temp[it-temp.begin()]=v[i];
    }
    cout<<temp.size()<<endl;

}