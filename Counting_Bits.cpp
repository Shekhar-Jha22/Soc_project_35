#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long smaller_pow(long long n){
    long long  count=0;
    
    while(pow(2,count)<=n){
        count++;
    }
    return count-1;
}

long long perfect(long long n){
    if(n==0)return 1;
    
    return pow(2,n-1)+2*perfect(n-1)-1;
}

long long total_ones(long long n){
    long long power=smaller_pow(n);
    if(n==1)return 1;
    else if(n==0)return 0;
    return perfect(power)+total_ones(n-pow(2,power))+n-pow(2,power);
}

int main(){
    int n;
    cin>>n;
    cout<<total_ones(n)<<endl;
}