#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n;
        cin>>n>>m;
        int arr[n][m];
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                
                arr[i][j]=s[j]-'0';
            }
        }
        bool cond=false;
        if(m==1 || n==1){
            cout<<"yes"<<endl;
            cond=true;
        }
        
        
        else{
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(arr[i][j]==1 && arr[i-1][j]==0 && arr[i][j-1]==0){
                        cout<<"no"<<endl;
                        cond=true;
                        break;
                    }
                    if(cond)break;
                }
            }
        }
        if(!cond)cout<<"yes"<<endl;
    }
}