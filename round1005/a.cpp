#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        vector<int>sum;
        for(int i=0;i<n;i++){
            if(i==0)sum.push_back(v[0]);
            else if(sum.back()*v[i]>=0)sum.back()+=v[i];
            else sum.push_back(v[i]);
        }
        int positive=0,negative=0;
        for(int i=0;i<sum.size();i++){
            if(sum[i]>0)positive++;
            else negative++;
        }
        vector<int>v1;
        int pos1=0,neg1=0;
        for(int i=0;i<sum.size();i++){
            if(v1[i]>0){
                v1[i]=0;
                for(int j=i;j<sum.size();j++){
                    v1[i]+=abs(sum[j]);
                }
            }
            else if(v1[i]<0){
                v1[i]=0;
                for(int j=i;j>=0;j--){
                    v1[i]+=abs(sum[j]);
                }
            }
        }
        int max=0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]>max)max=v1[i];
            cout<<v1.size();
        }
        cout<<max<<endl;
    }
}