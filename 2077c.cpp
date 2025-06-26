#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<2*n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        long long int a=0,b=0;
        for(int i=0;i<n-1;i++){
            a+=v[i];
        }
        for(int i=n-1;i<2*n;i++){
            b+=v[i];
        }
        for(int i=0;i<2*n+1;i++){
            if(i==1)cout<<b-a<<" ";
            else if(i%2==0){
                cout<<v[n-1+i/2]<<" ";
            }
            else {
                cout<<v[i/2-1]<<" ";
            }
        }
        cout<<endl;
    }
}