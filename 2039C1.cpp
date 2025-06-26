#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int x,m;
        cin>>x>>m;
        int result=0;
        for(int i=1;i<=m;i++){
            if(i!=x){
                int x0=x^i;
                // cout<<x0;
                if(i%x0 ==0 || x%x0 == 0)result++;
            }
            
        }
        cout<<result<<endl;

    }
    
    
  
}