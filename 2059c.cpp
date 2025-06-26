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
            int c=0;
            vector<int>v1;
            for(int i=0;i<n;i++){
                int x;
                cin>>x;
                v1.push_back(x);
            }
            for(int i=n-1;i>=0;i--){
                if(v1[i]==1)c++;
                else break;
            }
            v.push_back(c);

        }
        sort(v.begin(),v.end());
        int x=0;
        for(int i=0;i<n;i++){
            if(v[i]<x)continue;
            else if(v[i]==x)x++;
            else {
                x++;
            }
        }
        cout<<x<<endl;
    }
}