#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];

    cout<<max(max_element(v.begin(),v.end())-v.begin(),v.end()-max_element(v.begin(),v.end())-1)<<endl;
}