#include<bits/stdc++.h>
using namespace std;

#define int long long 
int32_t main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>v(n,{0,0});
        int maxb=0;
        for(int i=0;i<n;i++){
            cin>>v[i].first;
            
        }
        for(int i=0;i<n;i++){
            cin>>v[i].second;
            maxb=max(maxb,v[i].second);
        }

        int bestprice=0;
        int l=0,r=maxb;

        while(l<=r){
            int mid=(l+r)/2;
            int penalties=0,totalprofit=0;
            for(int i=0;i<n;i++){
                if(mid>v[i].second)continue;
                else if(mid>v[i].first){
                    totalprofit+=mid;
                    penalties+=1;
                }
                else{
                    totalprofit+=mid;
                }
            }
            if(penalties<=k || ){
                bestprice=max(bestprice,totalprofit);
                l=mid+1;
            }
            else r=mid-1;
            
        }
        cout<<bestprice<<endl;
        
    }
}