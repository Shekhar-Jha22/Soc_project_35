#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> v1;
        vector<int> v2;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            v1.push_back(x);
        }
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            v2.push_back(x);
        }
        int sum=0;
        for(int j=0;j<n-1;j++){
            if(v1[j]>v2[j+1])sum+=(v1[j]-v2[j+1]);
        }
        cout<<sum+v1[n-1]<<endl;
    }
}