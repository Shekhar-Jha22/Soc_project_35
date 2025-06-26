#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int lval,rval;
        cin>>lval>>rval;

        int l=0,r=n-1;
        int index1=n,index2=-1;
        while(l<=r){
            int mid=(l+r)/2;

            if(v[mid]>=lval){
                index1=min(index1,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        l=0;
        r=n-1;
        while(l<=r){
            int mid=(l+r)/2;

            if(v[mid]<=rval){
                index2=max(index2,mid);
                l=mid+1;
            }
            else r=mid-1;
        }
        if(index1<=index2)
        cout<<index2-index1+1<<" ";
        else cout<<0<<" ";
    }
}