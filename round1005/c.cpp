#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool first=0;
        if(s[0]=='1')first=1;
        int count=0;
        for(int i=0;i<s.size()-1;i++){
            
            if(s[i+1]!=s[i])count++;

        }
        if(first)cout<<count+1<<endl;
        else cout<<count<<endl;
    }
}