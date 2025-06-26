#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int k;
        cin>>k;

        vector<int>v;
        int sum=0;
        int val=(sqrt(8*k+1)+1)/2;
        for(int i=0;i<val;i++){
            v.push_back(0);
        }
        k-=(val*(val-1))/2;
        sum+=val;
        int j=0;
        while(k!=0){
            int val=(sqrt(8*k+1)+1)/2;
            v[j]=(val);
            k-=(val*(val-1))/2;
            sum+=val;
            j++;
        }
        cout<<sum<<endl;
        int x=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i];j++){
                if(j==0)
                cout<<i<<" "<<0<<endl;
                else {
                    cout<<i<<" "<<x<<endl;
                    x++;
                }
            }
        }
    }
}