#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int A[n];
        int B[n];
        int C[n];
        
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A[i]=x;
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            B[i]=x;
            
        }
       
        
        long long int sum=0,mini=0,minimum=C[0];
        for(int i=0;i<n;i++){
            sum+=max(A[i],B[i]);
        }
        for(int i=0;i<n;i++){
           C[i]=min(A[i],B[i]);
        }
        sort(C,C+n);
        cout<<sum+C[n-1]<<endl;
        
    }
}