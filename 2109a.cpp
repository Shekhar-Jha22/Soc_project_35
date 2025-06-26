#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,count1=0;
        bool cond=true;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            if(x==1)count1++;
        }
        for(int i=1;i<n;i++){
            if(v[i]==0 && v[i-1]==0)cond=false;
        }
        if(!cond || count1==0 || count1==n)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}