#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(mp1[x])mp1[x]++;
            else mp1[x]=1;
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(mp2[x])mp2[x]++;
            else mp2[x]=1;
        }
        if(mp1.size()>2 || mp2.size()>2)cout<<"yes"<<endl;
        else if(mp1.size()==1 && mp2.size()==1)cout<<"no"<<endl;
        else if(mp1.size()==2 && mp2.size()==2)cout<<"yes"<<endl;
        else cout<<"no"<<endl;

       
    }
}