#include<iostream>
#include<string>
#include<vector>
using namespace std;



int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>output;
        int l=1,r=n;
        for(int i=n-1;i>=0;i--){
            if(i==0){
                output.push_back(l);
            }
            else if(s[i-1]=='>'){
                output.push_back(r);
                r--;
            }
            else{
                output.push_back(l);
                l++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<output[n-1-i]<<" ";
        }
        cout<<endl;
    }
}