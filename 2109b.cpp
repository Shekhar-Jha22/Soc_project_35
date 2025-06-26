#include<iostream>
#include<cmath>
using namespace std;

int val(int a){
    if(a==1)return 0;
    int x=1;
    while(pow(2,x)<a){
        x++;
       
    }
    return x;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        cout<<min(val(min((a-1),n-a)+1)+val(m),val(min((b-1),(m-b))+1)+val(n))+1<<endl;
    }
}