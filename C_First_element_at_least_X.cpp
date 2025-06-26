#include<bits/stdc++.h>
using namespace std;
#define int long long
class segtree{
    vector<int>original,v;
    int n,size;
    public:
    segtree(int _n,vector<int>& arr){
        original=arr;
        n=_n;

        int i=0;
        while((1<<i)<n)i++;

        size=(1<<i);

        v.resize(2*size,0);

        for(int i=0;i<n;i++){
            v[size+i]=original[i];
        }
        for(int i=size-1;i>=1;i--){
            v[i]=max(v[2*i],v[2*i+1]);
        }
    }

    void set(int ind,int val){
        set(ind,val,1,0,size-1);
    }
    void set(int ind,int val,int k,int l,int r){
        if(l==r){
            original[l]=val;
            v[k]=val;
        }
        else{
            int mid=(l+r)/2;

            if(ind<=mid)set(ind,val,2*k,l,mid);
            else set(ind,val,2*k+1,mid+1,r);

            v[k]=max(v[2*k],v[2*k+1]);
        }
    }

    int index(int val){
        return index(val,1,0,size-1);
    }
    int index(int val,int k,int l,int r){
        if(l==r && val>v[k])return -1;
        else if(l==r)return l;
        else if(v[2*k]>=val)return index(val,2*k,l,(l+r)/2);
        else return index(val,2*k+1,(l+r)/2+1,r);
    }
    
};

int32_t main(){
    int n,q;

    cin>>n>>q;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    segtree st(n,v);

    for(int i=0;i<q;i++){
        int q;
        cin>>q;
        if(q==1){
            int ind,val;
            cin>>ind>>val;
            st.set(ind,val);
        }
        else{
            int x;
            cin>>x;
            cout<<st.index(x)<<endl;
        }
    }

}