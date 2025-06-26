#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> v1;

    v.push_back(v[0]);

    for(int i=1;i<n;){
        if(v.size()==0){
            v1.push_back(v[i]);
            i++;
            continue;
        }
        else if(v[i]>v.back()){
            cout<<v[i]<<endl;
            v1.pop_back();
            continue;
        }
        else {
            i++;
        }
        v1.push_back(v[i]);
    }
}