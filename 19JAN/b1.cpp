#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<vector<int >>v;
        for(int i=0;i<n;i++){
        vector<int>v1;

        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            v1.push_back(x);
        }
        sort(v.begin(),v.end());
        v.push_back(v1);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                if(v[i][j+1]!=v[i][j]+n){
                    
                }
            }
        }
    }
}