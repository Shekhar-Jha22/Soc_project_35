#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        int val1=0,first0=31;
        for(int i=0;i<31;i++){
            if(x&1<<i)val1++;
            else first0=min(first0,i);
        }
        if(n==1 && x==0)cout<<-1<<endl;
        else if(n<=val1)cout<<x<<endl;
        else if(n==val1+1)cout<<x+pow(2,first0+1)<<endl;
        else if((n-val1)%2 && x==0)cout<<x+n+3-val1<<endl;
         else if((n-val1)%2 )cout<<x+n+1-val1<<endl;
        else cout<<x+n-val1<<endl;

    }
}