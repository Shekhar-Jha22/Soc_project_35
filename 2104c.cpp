#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int counta=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A')counta++;
        }
        if(counta==s.size())cout<<"Alice"<<endl;
        else if(counta==0)cout<<"Bob"<<endl;
        else if(s.size()==2){
            if(s[0]=='A')cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else if(counta==1)cout<<"Bob"<<endl;
        else if(counta==s.size()-1)cout<<"Alice"<<endl;
        else if((s[s.size()-1]=='A' && s[0]=='A')||(s[s.size()-1]=='A' && s[s.size()-2]=='A') )cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}