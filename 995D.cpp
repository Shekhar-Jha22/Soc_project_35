#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int >v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);    
        }
        int count=0,sum=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((sum-(v[i]+v[j]))>=x)
                    if((sum-(v[i]+v[j]))<=y)count++;
                
            }
        }
        v.erase(v.begin(),v.end());
        cout<<count<<endl;
    }
}