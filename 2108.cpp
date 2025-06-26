#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v;
        int total=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(i==0)v.push_back(x);
            else{
                if(x!=v.back())
                v.push_back(x);
            }
        }
        if(v.size()==1 || v.size()==2)cout<<1<<endl;
        else{
            for(int i=1;i<v.size()-1;i++){
                if(v[i]<v[i-1] && v[i]<v[i+1])total++;
            }
            cout<<total+1<<endl;
        }
    }
}