#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        if((p1+p2+p3)%2){
            cout<<-1<<endl;
            continue;
        }
        int sum=0;
        while(p1+p2>p3 ){
            if(p1==0)break;
            sum+=1;
            p1-=1;
            p2-=1;
        }
        sum+=min((p1+p2),p3);
        cout<<sum<<endl;
    }
}