#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double n,m,k;
        cin>>n>>m>>k;
        int x=ceil(k/n);
        cout<<int64_t(ceil(x/(m+1-x)))<<endl;
    }
}