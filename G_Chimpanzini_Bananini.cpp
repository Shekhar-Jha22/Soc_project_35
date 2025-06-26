#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        deque<int>v;
        int sum=0,rizz=0,count=0;
        bool straight=true;
        int nops;
        cin>>nops;

        for(int i=0;i<nops;i++){
            int operation;
            cin>>operation;
            if(operation==1){
                if(!v.empty()){
                    if(straight){
                        rizz+=(sum-count*v.back());
                        int val=v.back();
                        v.pop_back();
                        v.push_front(val);
                    }
                    else{
                        rizz+=(sum-count*v.front());
                        int val=v.front();
                        v.pop_front();
                        v.push_back(val);
                    }
                }
            }
            else if(operation==2){
                rizz=(count+1)*sum-rizz;
                straight=!straight;
            }
            else{
                int x;
                cin>>x;
                if(straight)v.push_back(x);
                else v.push_front(x);
                count++;
                sum+=x;
                rizz+=count*x;
            }
            cout<<rizz<<endl;
        }
    }
}