#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        bool cond=true;
        cin>>n;
        vector<int>v;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                cout<<"no"<<endl;
                cond=false;
                break;
            }
            
            
            v[i+1]=v[i+1]-v[i];
            v[i]=0;
            
        }
        if(cond){
            cout<<"yes"<<endl;
        }
    }
}