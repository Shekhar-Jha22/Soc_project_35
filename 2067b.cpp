#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>>v1;
        for(int i=0;i<n;i++){
            if(i==0)v1.push_back({v[0],1});
            else{
                if(v1.back().first!=v[i])v1.push_back({v[i],1});
                else v1.back().second++;
            }
        }
        bool cond=false,cond1=true;
        int posn=0,remainder=0;
        for(int i=0;i<v1.size();i++){
            if(i!=0){
                if(cond==false && v1[i].first>posn){
                    
                    cond1=false;
                    break;
                }
                else if(cond==false && v1[i].first<posn){
                    posn=posn+(1+v1[i].second)/2-1;
                    remainder=(remainder+v1[i].second)%2;
                }
                else if(cond==true && v1[i].first>posn){
                    posn=v1[i].first+ceil((v1[i].second+remainder)/2)-1;
                    remainder=(remainder+v1[i].second)%2;
                }
                else if(cond==true && v1[i].first<posn){
                    posn+=(ceil((v1[i].second+remainder)/2)-1);
                    remainder=(remainder+v1[i].second)%2;
                }
            }
            if((remainder)%2==1)cond=false;
            else cond=true;
            
            
        }
        cout<<cond;
        if(cond1 && cond)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}