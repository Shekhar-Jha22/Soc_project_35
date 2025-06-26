#include<bits/stdc++.h>
using namespace std;
#define int long long

int power(int n){
    for(int i=0;i<62;i++){
        if((1<<i)>n)return (1<<i);
    }
}

int32_t main(){
    int n,q;
    cin>>n>>q;
    int a=power(n);
    vector<int>v(2*a,0);
    for(int i=a;i<a+n;i++){
        cin>>v[i];
    }
    for(int i=a-1;i>=1;i--){
        v[i]=v[2*i]+v[2*i+1];
    }
    for(int i=0;i<q;i++){
        int que,x,y;
        cin>>que>>x>>y;
        if(que==1){
            int val=a+x-1,val1=v[val];
            v[val]=y;
            val=val/2;
            while(val!=0){
                v[val]+=(y-val1);
                val/=2;
            }
        }
        else{
            int sum=0;
            x+=(a-1);

            y+=(a-1);
            while (x <= y) {
                if (x % 2 == 1) sum +=  v[x++];
                if (y % 2 == 0) sum +=  v[y--];
                x /= 2;
                y /= 2;
            }
            cout<<sum<<endl;
        }
    }

    return 0;
}