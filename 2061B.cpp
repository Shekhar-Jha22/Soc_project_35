#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int >v;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int a,b,c;
        bool cond=false;

        for(int i=v.size()-1;i>=1;i--){
            if(v[i]==v[i-1]){
                c=v[i];
                cond=true;
                v.erase(v.begin()+i-1);
                v.erase(v.begin()+i-1);
                break;
            }
        }
        bool cond1=false;
        if(!cond){
            cout<<-1<<endl;
            continue;
        }
        
        else {
            for(int i=0;i<v.size()-1;i++){
                if((v[i+1]-v[i])<2*c){
                    a=v[i];
                    b=v[i+1];
                    cond1=true;
                    break;
                }
            }
        }
        if(!cond1)cout<<-1<<endl;
        else cout<<a<<" "<<b<<" "<<c<<" "<<c<<endl;
    }
}
