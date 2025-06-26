#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x;
        cin>>x;
        bool cond=false;
        string s;
        while(x!=0){
            int rem=x%2;
            if(rem==1)s+='1';
            else s+='0';
            x=x/2;
        }
        int l=s.size(),s0=0,s1=0;
        for(int i=0;i<l;i++){
            if(s[i]=='0')s0++;
            else s1++;
        }
        int posn=0;
        bool cond1=false;
        for(int i=0;i<l-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
                posn=i;
                break;
            }
            if(s[i]=='1' && s[i+1]=='0'){
                posn=i;
                break;
            }


        }
        int a=0;
        if(s1==l || s0==l-1  || cond1 ){
            cout<<-1<<endl;
            continue;
        }
        
        else{
            
            for(int i=0;i<=posn+1;i++){
                a+=pow(2,i);
            }
            cout<<a<<endl;
            
        } 
    }
}