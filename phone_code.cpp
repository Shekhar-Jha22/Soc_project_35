#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<string>v;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int max=0;
    bool cond=true;
    for(int i=0;i<v[0].size();i++){
        string sub=v[0].substr(0,i+1);
        for(int j=0;j<n;j++){
            if(v[j].substr(0,i+1)!=sub){
                cond=false;
                break;
            }
        }
        if(cond)max++;
        else break;
    }
    cout<<max;
}