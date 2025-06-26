#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,a,b,c;
        cin>>m>>a>>b>>c;

        if(a>m && b>m){
            cout<<2*m<<endl;
        }
        else if(a>=m && b<=m){
            cout<<(b+c>m?2*m:m+b+c)<<endl;
        }
        else if(b>=m && a<=m){
            cout<<(a+c>m?2*m:m+a+c)<<endl;
        }
        else {
            cout<<(a+b+c>2*m?2*m:a+b+c)<<endl;
        }
    }
}