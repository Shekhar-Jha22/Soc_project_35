#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int >v;
        for(int j=0;j<(n*(n-1))/2;j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
    
        int a=0;
        for(int j=n;j>1;j--){
            cout<<v[a]<<" ";
            a+=(j-1);
        }
        cout<<v[v.size()-1];
        cout<<endl;
    }
}