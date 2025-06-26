#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<long long>v;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            if(i==0)v.push_back(x);
            else if(v.back()>0 && x>0)v.back()+=x;
            else if(v.back()<=0 && x<=0)v.back()+=x;
            else v.push_back(x);
        }
       long long negsum=0;
       for(int i=0;i<v.size();i++){
            if(v[i]<0)negsum-=v[i];
       }
       long long maximum=negsum;
       for(int i=0;i<v.size();i++){
        negsum+=v[i];
        maximum=max(maximum,negsum);
       }
       cout<<maximum<<endl;
    }
}