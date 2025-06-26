#include<bits/stdc++.h>
using namespace std;

class segtree{
    vector<int>original,v;
    int n,size;
    public:
    segtree(int _n,vector<int>&arr){
        n=_n;
        original=arr;
        int i=0;
        while((1<<i)<n)i++;
        size=(1<<i);

        v.resize(2*size,0);

        for(int i=0;i<n;i++){
            v[size+i]=original[i];
        }
        for(int i=size-1;i>=1;i--){
            v[i]=v[2*i]+v[2*i+1];
        }
    }

    void set(int index){
        set(index,1,0,size-1);
    }
    void set(int ind,int k,int l,int r){
        if(l==r){
            original[l]=original[l]^(1LL);
            v[k]=v[k]^(1LL);
        }
        else{
            int mid=(l+r)/2;
            if(mid>=ind){
                set(ind,2*k,l,mid);
            }
            else set(ind,2*k+1,mid+1,r);

            v[k]=v[2*k]+v[2*k+1];
        }
    }

    int posn(int val){
        return posn(val,1,0,size-1);
    }
    int posn(int val,int k,int l,int r){
        if(l==r)return r;
        else{
            if(val>=v[2*k])return posn(val-v[2*k],2*k+1,(l+r)/2+1,r);
            else return posn(val,2*k,l,(l+r)/2);
        }
    }
};

int32_t main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n,0);

    for(int i=0;i<n;i++)cin>>v[i];

    segtree st(n,v);

    for(int i=0;i<q;i++){
        int q,val;
        cin>>q>>val;
        if(q==1)st.set(val);
        else cout<<st.posn(val)<<endl;
    }
}