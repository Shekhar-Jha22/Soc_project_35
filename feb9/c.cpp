#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<int>a;
        vector<int>b;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            b.push_back(x);
        }
        vector<int>a1;

        for(int i=0;i<n;i++){
           a1.push_back(b[0]-a[i]);
            
        }
        vector<int>result;
        bool cond=true;

        for(int i=0;i<n;i++){
            if(i==0)result.push_back(min(a[0],a1[0]));
            else {
                if(min(a[i],a1[i])>=result.back())result.push_back(min(a[i],a1[i]));
                else if(max(a[i],a1[i])<result.back()){
                    cond=false;
                    break;
                }
                else {
                    result.push_back(max(a[i],a1[i]));
                }
            }
        }
        if(cond)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}