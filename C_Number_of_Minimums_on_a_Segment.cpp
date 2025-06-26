#include<bits/stdc++.h>
using namespace std;
#define int long long
class segtree{
    vector<int>original;
    vector<pair<int,int>>v;
    int n,size;
    
    public:
    segtree(int _n,vector<int>& arr){
        n=_n;
        original=arr;

        int i=0;
        while((1<<i)<n)i++;

        size=(1<<i);

        v.resize(2*size,{INT64_MAX,1});

        for(int i=0;i<n;i++){
            v[i+size].first=original[i];
        }
        for(int i=size-1;i>=1;i--){
            pair<int,int>p1=v[2*i],p2=v[2*i+1];

            v[i].first=min(p1.first,p2.first);
            if(p1.first==p2.first)v[i].second=p1.second+p2.second;
            else if(p1.first<p2.first)v[i].second=p1.second;
            else v[i].second=p2.second;
        }
    }
        void update(int ind,int val){
            update(ind,val,1,0,size-1);
        }
        void update(int ind,int val,int k,int l,int r){
            if(l==r){
                original[ind]=val;
                v[k].first=val;
            }
            else{
                int mid=(l+r)/2;

                if(ind<=mid)update(ind,val,2*k,l,mid);
                else update(ind,val,2*k+1,mid+1,r);

                pair<int,int>p1=v[2*k],p2=v[2*k+1];
                v[k].first=min(p1.first,p2.first);
                if(p1.first==p2.first)v[k].second=p1.second+p2.second;
                else if(p1.first<p2.first)v[k].second=p1.second;
                else v[k].second=p2.second;
            }
        }

        pair<int,int> minval(int l,int r){
            return minval(l,r,1,0,size-1);
        }
        pair<int,int> minval(int l,int r,int k,int lx,int rx){
            if(rx<l || r<lx)return make_pair(INT64_MAX,1);
            if(l<=lx && rx<=r)return v[k];
            pair<int,int>p1=minval(l,r,2*k,lx,(lx+rx)/2),p2=minval(l,r,2*k+1,(lx+rx)/2+1,rx);
            if(p1.first==p2.first)return make_pair(p1.first,p1.second+p2.second);
            else if(p1.first<p2.first)return p1;
            else return p2;
        }
    }
;

int32_t main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];

    segtree st(n,v);

    for(int i=0;i<q;i++){
        int q;
        cin>>q;
        if(q==1){
            int i,val;
            cin>>i>>val;
            st.update(i,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            r--;
            cout<<st.minval(l,r).first<<" "<<st.minval(l,r).second<<endl;
        }
    }
}