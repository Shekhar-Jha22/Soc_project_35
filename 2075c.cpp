#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,sum=0;
        cin>>n>>m;
        vector<int>v,sumarr;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(x==n)x--;
            v.push_back(x);
            sum+=x;
        }
        for(int i=0;i<m;i++){
            sumarr.push_back(sum);
            sum-=v[i];
        }

        sort(v.begin(),v.end());
        long long int sum=0;
        int a=0,b=m-1;
        
        cout<<sum<<endl;
    }
}