#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        bool cond=false;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                cout<<1<<endl;
                cond=true;
                break;
                
                }
            
        }
        if(!cond)cout<<s.size()<<endl;
    }
}