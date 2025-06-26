#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool diff=false;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1])diff=true;
        }
        string s1=s;
        reverse(s1.begin(),s1.end());
        if(s1==s &&  !k)cout<<"no"<<endl;
        else if(s1==s && k && !diff)cout<<"no"<<endl;
        else if(s1==s && k && diff)cout<<"yes"<<endl;
        else{
            if(k)cout<<"yes"<<endl;
            else{
                if(s1<s){
                    cout<<"no"<<endl;
                }
                else cout<<"yes"<<endl;
            }
        }

    }
}