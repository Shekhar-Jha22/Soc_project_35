#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();

    sort(s.begin(),s.end());
    
    char c=s[n-1];
    int posn;
    for(int i=0;i<n;i++){
        if(s[i]==c){
            cout<<s[i];
        }
    }

}