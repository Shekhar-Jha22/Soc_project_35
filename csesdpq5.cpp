#include<iostream>
#include<cmath>
using namespace std;

int maxdigit(int n){
    int maximum=0;
    while(n!=0){
        int digit=n%10;
        maximum=max(maximum,digit);
        n=n/10;
    }
    return maximum;
}

int dp(int n){
    if(n<10)return 1;
    
    return dp(n-maxdigit(n))+1;
}

int main(){
    int n;
    cin>>n;
    cout<<dp(n)<<endl;
}