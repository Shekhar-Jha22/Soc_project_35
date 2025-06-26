#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k,x=1;
        cin>>n>>k;

        int A[n];
        for(int i=0;i<n;i++){
            A[i]=0;
        }
        while(x*k<=n){
            A[x*k-1]=x;
            x++;
        }
       
        if((x-1)*k!=n){
            A[n-1]=x;
            x++;
        }
        for(int i=0;i<n;i++){
            if(A[i]==0){
                A[i]=x;
                x++;
            }

        }
        for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
}