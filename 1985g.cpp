#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int power(long long x, unsigned int y, int p) 
{ 
    int res = 1;     // Initialize result 

    x = x % p; // Update x if it is more than or 
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 

        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int l,r,k;
        cin>>l>>r>>k;
        
        int x=ceil(10.0/k),res=pow(10,9)+7;
        
        int val=power(x,r,pow(10,9)+7)-power(x,l,pow(10,9)+7);

        if(val>=0)
        cout<<power(x,r,pow(10,9)+7)-power(x,l,pow(10,9)+7)<<endl;
        else 
        cout<<res+val<<endl;
    }
}