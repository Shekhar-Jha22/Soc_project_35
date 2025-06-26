#include<bits/sdtc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>adj[n];

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>a>>b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
    }
}