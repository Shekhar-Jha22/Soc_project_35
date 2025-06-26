#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        long long int sum=0;
        int nodd=0,maxi=0;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sum+=x;
            if(x%2==1)nodd++;
            maxi=max(maxi,x);
        }
        if(nodd==n || nodd==0)cout<<maxi<<endl;
        else cout<<(sum+1-nodd)<<endl;
    }
}