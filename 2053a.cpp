#include<iostream>
#include<vector>
#include<algorithm>
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
        
        bool cond=false;
        for(int i=0;i<n-1;i++){
            if(max(v[i],v[i+1])<2*min(v[i],v[i+1]))cond=true;
        }
        if(cond)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}