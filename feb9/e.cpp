#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        cin>>m>>n>>k;
        if(abs(n-m)>k){
            cout<<-1<<endl;
            continue;
        }
        if(k>max(n,m)){
            cout<<-1<<endl;
            continue;
        }
        else {
            if(n==max(n,m)){
                for(int i=0;i<k;i++)cout<<1;
                for(int i=0;i<n-k;i++)cout<<"01";
                for(int i=0;i<m+k-n;i++)cout<<0;
                cout<<endl;
            }
            else if(m==max(n,m)){
                for(int i=0;i<k;i++)cout<<0;
                for(int i=0;i<m-k;i++)cout<<"10";
                for(int i=0;i<n+k-m;i++)cout<<1;
                cout<<endl;
            }
        }

    }
}