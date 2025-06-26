#include<bits/stdc++.h>
using namespace std;

void check(int remainder,int count2,int count3){
   
    if(remainder==18)cout<<"yes";
    else if(remainder>6*count3+2*count2){
        cout<<"no";
    }
    else if(remainder%6==0){
        int a=count2,b=count3;
        count3+=a/3;
       
        if(remainder/6<=count3 )cout<<"yes";
        else cout<<"no";
    }
    else if(remainder%6==2){
        int a=count2,b=count3;
        if(a>0)a--;
        count3+=a/3;
        if(count2>0 && remainder/6<=count3)cout<<"yes";
        else cout<<"no";
    }
    else if(remainder%6==4){
        int a=count2,b=count3;
        if(a>1)a-=2;
        count3+=a/3;
        if(count2>1 && remainder/6<=count3)cout<<"yes";
        else cout<<"no";
    }

}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;

        long long int count2=0,count3=0,sum=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='2')count2++;
            else if(s[i]=='3')count3++;

            sum+=(s[i]-'0');
        }

        int remainder=9-sum%9;

        if(remainder%2==1)remainder+=9;

        check(remainder,count2,count3);
        cout<<endl;
    }
}