#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int x;
            cin>>x;
            if(x==1){
                a=i;
                b=j;
                break;

            }
        }
    }
    cout<<abs(2-a)+abs(2-b);
}