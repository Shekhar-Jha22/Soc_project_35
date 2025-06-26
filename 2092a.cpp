#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
      
        
            int x;
            cin>>x;
            int mini=x,maxu=x;
        for(int i=0;i<n-1;i++){
            
            int x;
            cin>>x;
           
            mini=min(mini,x);
            maxu=max(maxu,x);
        }
        cout<<maxu-mini<<endl;
    }
}