#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    unordered_map<char,int> mp;

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]==0)mp[s[i]]=1;

    }

    if(mp.size()%2==1)cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
}