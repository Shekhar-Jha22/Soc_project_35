#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int l=s.size();
        cout<<s.substr(0,l-2)+'i'<<endl;
    }
}