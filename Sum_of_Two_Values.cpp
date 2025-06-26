#include<bits/stdc++.h>
using namespace std;

int main(){
    double n,s;
    cin>>n>>s;
    map<int,int>mp;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(mp[x]!=0 && x==(s/2)){
            cout<<mp[x]<<" "<<i+1<<endl;
            return 0;
        }
        else if(mp[s-x]!=0){
            cout<<mp[s-x]<<" "<<i+1<<endl;
            return 0;
        }
        else mp[x]=(i+1);
    }
    cout<<"IMPOSSIBLE"<<endl;
}