#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string p;
        cin>>p;
        string s;
        cin>>s;
        vector<int>v1,v2;
        v1.push_back(1);
        v2.push_back(1);
        for(int i=1;i<p.size();i++){
            if(p[i]==p[i-1])v1.back()++;
            else v1.push_back(1);
        }
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])v2.back()++;
            else v2.push_back(1);
        }
        bool cond=true;
        if(s[0]!=p[0] || v1.size()!=v2.size())cond=false;
        else{
            for(int i=0;i<v1.size();i++){
                if((v2[i]>2*v1[i]) || (v2[i]<v1[i]))cond=false;
            }
        }
        if(cond)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}