#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        vector<int>v(s.size());
        for(int i=0;i<s.size();i++){
            v[i]=s[i]-'0';
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]-1>v[i]){
                v[i+1]--;
                swap(v[i],v[i+1]);
            }
        }
        for(int i=0;i<v.size();i++)cout<<v[i];
        cout<<endl;
    }
}