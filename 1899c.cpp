#include<iostream>
#include<vector>

using namespace std;

int sub_sum(int l,int r,vector<int>v){
    int a=l,b=r,sum=0;
    
    for(int i=l;i<=r;i++){
        sum+=v[i];
    }
    int maximum=sum;
        for(int i=0;i<r-l;i++){
            if(v[a]>v[b]){
                sum-=v[b];
                b--;
            }
            else {
                sum-=v[a];
                a++;
            }
            maximum=max(maximum,sum);
        }
        return maximum;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v;
        vector<pair<int,int>>posn;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            
        }
        for(int i=0;i<n-1;i++){
            if(v[i]%2==v[i+1]%2)posn.push_back({i,i+1});
        }
        
        
    }
}
