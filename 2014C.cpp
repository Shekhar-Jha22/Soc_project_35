#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n,sum=0;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            sum+=x;
        }
        if(n==1 || n==2){
            cout<<-1<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        if(sum>2*n*v[n/2])cout<<0<<endl;
        else
        cout<<2*n*v[n/2]-sum+1<<endl;
    }
}