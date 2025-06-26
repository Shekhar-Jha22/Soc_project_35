#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int >v;
        vector<int>v1,v3;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            if(x==1)v1.push_back(i);
            
            if(x==3)v3.push_back(i);
        }
        long long int sum=0;
        for(int i=0;i<v1.size();i++){
            int x=0;
            for(int j=0;j<n;j++){
                
                if(v[j]==3 && j>v1[i]){
                    sum+=(pow(2,j-v[i]-1-x)-1);
                    x++;
                    sum%=998244353;
                }
            }
        }
        cout<<sum<<endl;
    }
} 