#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<int> left;
        vector<int>right;
        
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            left.push_back(x);
            
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            right.push_back(x);
           
        }
        long long sum=0;
        vector<int>c;
        for(int i=0;i<n;i++){
            if(left[i]<right[i]){
                sum+=right[i];
                c.push_back(left[i]);
            }
            else{
                sum+=left[i];
                c.push_back(right[i]);
            }
        }
        sort(c.begin(),c.end());
        if(k!=1)
        for(int i=n-1;i>n-k;i--){
            sum+=c[i];
        }
        cout<<sum+1<<endl;
    }
}