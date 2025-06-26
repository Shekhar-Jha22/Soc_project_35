#include<iostream>
using namespace std;

long long  value(long long l,long long r,long long k){
    if(r-l+1<k)return 0;
    if(l==r)return l;
    else if((r-l+1)%2==0)return value(l,(l+r)/2,k)+value((l+r)/2+1,r,k);
    else return value(l,(l+r)/2-1,k)+value((l+r)/2+1,r,k)+(l+r)/2;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long n,k;
        cin>>n>>k;
        cout<<value(1,n,k)<<endl;
    }
}