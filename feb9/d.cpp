#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n,m;
        cin>>n>>m;
        
        vector<pair<int,vector<long long int>>>v1;
       
        for(int i=0;i<n;i++){
            vector<long long int>v;
            int sum=0,sum1=0;
            for(int i=0;i<m;i++){
                int x;
                cin>>x;
                v.push_back(x);
                sum+=((m-i)*x);
                sum1+=x;
            }
            v1.push_back({sum1,v});
        }
        sort(v1.begin(),v1.end());

        long long int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=v1[n-1-i].second[j]*((n-i)*(m)-j);
            }
        }
        cout<<sum<<endl;
    }
}