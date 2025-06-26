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
        vector<int >v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            
        }
        sort(v.begin(),v.end());
        int count=0;
        int left=0;
        int right=n-1;
        for(int i=0;i<n;i++){
            int sum=v[left]+v[right];

            if(sum==k){
                count++;
                left++;
                right--;
            }
            else if(sum>k){
                right--;
            }
            else if (sum<k){
                left++;
            }
            if(left>=right)break;
            
        }
        cout<<count<<endl;
    }
}