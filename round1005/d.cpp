#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,q;
        cin>>n>>q;
        vector<int>N;
        
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            N.push_back(x);
        }
        for(int i=0;i<q;i++){
            vector<int>v=N;
            int x,score=0;
            cin>>x;
            for(int i=n-1;i>=0;i--){
                if(x>=v[i]){
                    score++;
                    x=x^v[i];
                }
                else break;
            }
            cout<<score<<" ";
        }
        cout<<endl;
    }
}