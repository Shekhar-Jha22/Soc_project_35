#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        string s;
        cin>>s;

        cout<<count(s.begin(),s.end(),'1')<<endl;
    }
}