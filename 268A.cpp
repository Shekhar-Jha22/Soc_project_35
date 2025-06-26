#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int p;
    cin>>p;

    unordered_map<int,int> mp1;

    for(int i=0;i<p;i++){
        int x;
        cin>>x;
        mp1[x]=1;
    }
    int q;
    cin>>q;

    unordered_map<int,int> mp2;

    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        mp2[x]=1;
    }
    bool cond=true;

    for(int i=1;i<=n;){
        if(mp1[i])i++;
        else {
            if(mp2[i])i++;

            else {
                cond=false;
                break;
            }
        }
    }
    if(cond){
        cout<<"I become the guy.";

    }
    else cout<<"Oh, my keyboard!";
}