#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x=0,val=0;
        while(x<n-2){
            int current=s[x]-'0';
            int next=s[x+1]-'0';

            if(current==next){
                x++;
                val++;
            }
            else {
                x+=2;
                val++;
            }
        }
        if(x==n-2){
            int current=s[x]-'0';
            int next=s[x+1]-'0';
            if(current==next){
                x++;
                val++;
            }
        }
        cout<<val<<endl;
    }
}