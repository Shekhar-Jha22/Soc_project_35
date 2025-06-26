#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n-2;i++){
            long long int x;
            cin>>x;
            v.push_back(x);
        }
        if(n<5){
            cout<<"yes"<<endl;
            continue;
        }
        else{
            bool cond=true;
            long long int one=v[0],two=v[1];
            for(int i=2;i<n-2;i++){
                long long int three=v[i];
                if(one==1 && two ==0 && three==1){
                    cout<<"no"<<endl;
                    cond=false;
                    break;
                }
                one=two;
                two=three;
            }
            if(cond){
                cout<<"yes"<<endl;
            }
        }
    }
}