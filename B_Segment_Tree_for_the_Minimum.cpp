#include<bits/stdc++.h>
using namespace std;
#define int long long
class segtree{
    vector<int>original;
    vector<int>v;
    int n,size;
    
    public:
    segtree(int _n,vector<int>& arr){
        n=_n;
        original=arr;

        int i=0;
        while((1<<i)<n)i++;

        size=(1<<i);

        v.resize(2*size,INT64_MAX);

        for(int i=0;i<n;i++){
            v[i+size]=original[i];
        }
        for(int i=size-1;i>=0;i--){
            v[i]=min(v[2*i],v[2*i+1]);
        }
    }
        void update(int ind,int val){
            update(ind,val,1,0,size-1);
        }
        void update(int ind,int val,int k,int l,int r){
            if(l==r){
                original[ind]=val;
                v[k]=val;
            }
            else{
                int mid=(l+r)/2;

                if(ind<=mid)update(ind,val,2*k,l,mid);
                else update(ind,val,2*k+1,mid+1,r);

                v[k]=min(v[2*k],v[2*k+1]);
            }
        }

        int minval(int l,int r){
            return minval(l,r,1,0,size-1);
        }
        int minval(int l,int r,int k,int lx,int rx){
            if(rx<l || r<lx)return INT64_MAX;
            else if(l<=lx && rx<=r)return v[k];
            else return min(minval(l,r,2*k,lx,(lx+rx)/2),minval(l,r,2*k+1,(lx+rx)/2+1,rx));
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
            cout<<st.minval(l,r)<<endl;
        }
    }
}