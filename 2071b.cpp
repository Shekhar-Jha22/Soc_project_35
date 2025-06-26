#include<bits/stdc++.h>
using namespace std;

bool check(double x){
    if(sqrt(x)==floor(sqrt(x)))return true;
    else return false;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double n;
        cin>>n;
        if(check(n*(n+1)/2)){
            cout<<-1<<endl;
            continue;
        }
        else{
            for(int i=1;i<=n;){
                double x=(i*(i+1))/2;
                if(check(x)){
                    cout<<i+1<<" "<<i<<" ";
                    i+=2;
                }
                else {
                    cout<<i<<" ";
                    i+=1;
                }
            }
            cout<<endl;
        }
    }
}