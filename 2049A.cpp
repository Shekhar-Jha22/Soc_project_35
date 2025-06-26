#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        vector<int>v;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        vector<int>v1=v;
        int count=0,count1=0;
        bool cond=false;
        for(int i=0;i<n;i++){
            if(v[i]==0)count++;
            else break;
        }
        if(count==n){
            cout<<0<<endl;
            continue;
        }
        sort(v1.begin(),v1.end());
        for(int i=0;i<n;i++){
            if(v1[i]==0 )count1++;
            else break;
        }
        for(int i=count;i<n;i++){
            if(v[i]==0 && i<(n-count1+count)){
                cond=true;
                break;
            }
           
        }
        if(cond)cout<<2<<endl;
        else cout<<1<<endl;
    }
}