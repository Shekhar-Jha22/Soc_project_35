#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s1,s2;
        cin>>s1>>s2;
        int l=s1.size();
        bool cond=false;
        for(int i=0;i<l-1;i++){
            if(s1[i]=='0' && s1[i+1]=='1' && s2[i]=='0' && s2[i+1]=='1'){
                cout<<"yes"<<endl;
                cond=true;
                break;
            }
        }
        if(!cond)cout<<"no"<<endl;
    }
}