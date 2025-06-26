#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
   
    unordered_map<int,int>X;
    unordered_map<int,int>Y;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        X[x]++;
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        Y[x]++;
    }
    long long int count=0;
    for(auto x:X){
        count+=x.second*(long long)Y[x.first];
    }
    cout<<count;
}