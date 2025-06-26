#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<int>a;
        vector<int>b;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        int minimum=-2;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            b.push_back(x);
            if(x!=-1){
                minimum=min(minimum,(a[i]+x));
            }
        }

    }
}