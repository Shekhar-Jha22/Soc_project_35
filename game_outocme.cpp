#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int num=0;
    cin>>n;

    if(n==1){
        int x;
        cin>>x;
        cout<<0;
    }

    else {
        int A[n][n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                A[i][j]=x;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int colsum=0,rowsum=0;
                for(int k=0;k<n;k++){
                    colsum+=A[k][j];
                }
                for(int k=0;k<n;k++){
                    rowsum+=A[i][k];
                }   
                if (colsum>rowsum) num++;
            }
        }
        cout<<num;
    }
    
}