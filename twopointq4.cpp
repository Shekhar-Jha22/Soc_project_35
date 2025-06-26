#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,s;
    cin>>n>>s;
    vector<int>A;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
       
    }
    int a=0,b=0,sum=0,maximum=0;
    while(true){
        if( b==n){
            
            break;
        }
        else  if(sum>s){
            sum-=A[a];
            a++;
            
        }
        else{
            sum+=A[b];
            b++;
            
        }
        maximum=max(maximum,b-a+1);
        
    }
    cout<<maximum;
}