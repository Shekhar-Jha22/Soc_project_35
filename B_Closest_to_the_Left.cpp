#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n,0);

    for(int i=0;i<n;i++)cin>>v[i];

    for(int i=0;i<q;i++){
        int val;
        cin>>val;

        int l=0,r=n-1;
        bool found=false;
        int index=-1;

        while(l<=r){
            int mid=(l+r)/2;

            if(v[mid]<=val){
                found=true;
                index=max(index,mid);
                l=mid+1;
            }
            else if(v[mid]>val)r=mid-1;
        }

        if (found)cout<<index+1<<endl;
        else cout<<0<<endl;
    }
}