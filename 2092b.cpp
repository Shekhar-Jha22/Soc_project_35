#include<iostream>
#include<string>
#include<cmath>
using  namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int x1=0,x2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(a[i]=='0')x1++;
            }
            else{
                if(b[i]=='0')x1++;
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(b[i]=='0')x2++;
            }
            else{
                if(a[i]=='0')x2++;
            }
        }
        if(x1>=ceil(n/2) && x2>=floor(n/2))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}