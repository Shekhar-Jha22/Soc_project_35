#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector<char>small;
        vector<char>big;

        

        for(int i=0;i<s.size();i++){
            if(s[i]-'a'>=0 && s[i]-'a'<26)small.push_back(s[i]);
            else big.push_back(s[i]);
        }
        int x=small.size(),y=big.size();

        for(int i=s.size()-1;i>=0;i++){
            
        }
    }
}