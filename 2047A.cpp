#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int num=1,count=0,sum=0;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sum+=x;

            if(sum==num*num){
                num+=2;
                count++;
            }
            else if(sum>num*num){
                while(num*num<sum){
                    num+=2;
                }
                if(sum==num*num){
                    count++;
                    num+=2;
                }
            }
        }
        cout<<count<<endl;
    }
}