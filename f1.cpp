#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            long long int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        long long int smallest=1;
        for(int i=1;i<n;i++){
            if(v[i]==v[0])smallest++;
            else break;
        }
        cout<<v[0]*n+n-smallest<<endl;
    }
}