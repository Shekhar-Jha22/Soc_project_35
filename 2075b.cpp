#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n,k;
        cin >>n>>k;
        vector<int>v,v1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        v1=v;
        long long int sum=0;
        if(k==1){
            if(v[0]>v[n-1]){
                sum+=v[0];
                sum+=*max_element(v.begin()+1,v.begin()+n);
            }
            else {
                sum+=v[n-1];
                sum+=*max_element(v.begin(),v.begin()+n-1);
            }
            
        }
        else{
            sort(v1.begin(),v1.end());
            for(int i=0;i<k+1;i++){
                sum +=v1[n-1-i];
            }
            
        }
        cout<<sum<<endl;
    }
}