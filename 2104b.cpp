#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long n,sum=0;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            sum+=x;
        }
        vector<long long>sumarr;
        vector<long long>maxelem;
        maxelem.push_back(v[0]);
        sumarr.push_back(sum);
        for(int i=1;i<n;i++){
            sumarr.push_back(sumarr.back()-v[i-1]);
            if(maxelem.back()>v[i])
            maxelem.push_back(maxelem.back());
            else maxelem.push_back(v[i]);
        }
        for(int i=0;i<n;i++){
            if(*max_element(v.begin(),v.end()-1-i)>v[n-i-1]){
                cout<<sumarr[n-i-1]+maxelem[n-i-1]-v[n-i-1]<<" ";
            }
            else cout<<sumarr[n-i-1]<<" ";
        }
        cout<<endl;
    }
}