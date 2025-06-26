#include<bits/stdc++.h>
using namespace std;

int main(){
    int l1,l2;
    cin>>l1>>l2;
    vector<int>v1(l1,0);
    vector<int>v2(l2,0);
    
    for(int i=0;i<l1;i++)cin>>v1[i];
    for(int i=0;i<l2;i++)cin>>v2[i];

    vector<vector<int>>arr(l1+1,vector<int>(l2+1,0));

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(v1[i-1]==v2[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }

    vector<int>str;
    int i=l1,j=l2;
    while(i>0 && j>0){
        if(v1[i-1]==v2[j-1]){
           str.push_back(v1[i-1]);
            i--;
            j--;
        }
        else if(arr[i-1][j]>arr[i][j-1]){
            i--;
        }
        else j--;
    }

    reverse(str.begin(),str.end());
    cout<<arr[l1][l2]<<endl;
    for(auto x:str){
        cout<<x<<" ";
    }
    cout<<endl;
}