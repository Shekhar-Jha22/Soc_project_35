#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        int arr[n][m];
        bool cond=m%k;

        if(cond){
            for(int i=0;i<n*m;i++){
                arr[i/m][i%m]=i%k+1;
            }
        }
        else {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    arr[i][j]=(j+i)%k+1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}