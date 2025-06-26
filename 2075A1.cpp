#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        cout<<2*(n/(2*k-1))+ceil((n-2*(n/(2*k-1))*(2*k-1))/k);
    }
}