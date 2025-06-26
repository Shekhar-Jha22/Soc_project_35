#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double n,s;
        cin>>n>>s;
        vector<double>v;
        for(int i=0;i<n;i++){
            double x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int back=n,teams=0;
        vector<int>scores;
        for(int i=n-1;i>=0;i--){
            scores.push_back(v[i]*(back-i));
            if(scores[n-1-i]>=s){
                back=i;
                teams++;
            }
        }
        cout<<teams<<endl;
    }
}