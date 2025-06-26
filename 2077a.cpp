#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
       int n,x;
       cin>>n>>x;
       vector<int>v;
       double sum=0;
       for(int i=0;i<n;i++){
        int s;
        cin>>s;
        v.push_back(s);
        sum+=s;
       } 
       if(sum/n==x)cout<<"yes"<<endl;
       else cout<<"no"<<endl;
    }
}