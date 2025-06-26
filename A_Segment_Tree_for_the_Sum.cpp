#include<bits/stdc++.h>
using namespace std;

class segtree{
    vector<int>original;
    vector<int>v;
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
            v[i+size]=original[i];
        }
        for(int i=size-1;i>=1;i--){
            v[i]=v[2*i]+v[2*i+1];
        }
    }

    void update(int ind,int val){
        update(ind,val,1,0,size-1);
    }
    void update(int i,int val,int k,int l,int r){
        if(l==r){
            original[l]=val;
            v[k]=val;
            return;
        }
        else{
            int mid=(l+r)/2;
            if(mid>=i){
                update(i,val,2*k,l,mid);
            }
            else update(i,val,2*k+1,mid+1,r);

            
        }
        v[k]=v[2*k]+v[2*k+1];
    }

    int sum(int l,int r){
        return sum(l,r,1,0,size-1);
    }
    int sum(int l,int r,int k,int lx,int rx){
        if(rx<l || lx>r)return 0;
        else if(rx<=r && lx>=l)return v[k];
        else return sum(l,r,2*k,lx,(lx+rx)/2)+sum(l,r,2*k+1,(lx+rx)/2+1,rx);
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n,0);

    for(int i=0;i<n;i++)cin>>v[i];
    segtree st(n,v);
    for(int i=0;i<q;i++){
        int que;
        cin>>que;
        if(que==1){
            int i,val;
            cin>>i>>val;
            st.update(i,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            r-=1;
            cout<<st.sum(l,r)<<endl;
        }
    }
}