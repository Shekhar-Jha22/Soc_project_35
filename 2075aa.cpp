#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        double k;
        cin>>n>>k;
        if(n<=k)cout<<1<<endl;
        else if(n%2==0)cout<<int(ceil(n/(k-1)))<<endl;
        else cout<<int(1+ceil((n-k)/(k-1)))<<endl;
    }
}