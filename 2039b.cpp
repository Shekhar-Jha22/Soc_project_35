#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        bool cond=false;
        
        int l=s.size();
        if(l==1){
            cout<<-1<<endl;
            cond=true;
            continue;
        }
        else if(l==2){
            if(s[0]==s[1])cout<<s<<endl;
            else cout<<-1<<endl;
            cond=true;
        }
        else {
            for(int i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1]){
                    cout<<s.substr(i,2)<<endl;
                    cond=true;
                    break;
                }
            }
            for(int i=0;i<s.size()-2;i++){
                
                if(s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2] && !cond){
                    cout<<s.substr(i,3)<<endl;
                    cond=true;
                    break;
                }
                
            }
        }
        if(!cond)cout<<-1<<endl;
    }
}