#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x1,x2,x3,y1,y2,y3,num=0;
    cin>>n>>m;

   

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;

            if(c=='*'){
                if(num==0){
                    x1=j;
                    y1=i;
                    num++;
                }
                else if(num==1){
                    x2=j;
                    y2=i;
                    num++;
                }
                else if(num==2){
                    x3=j;
                    y3=i;
                    num++;
                }
            }
            
        }
    }

    if(x1==x2 && y1==y3){
        cout<<y2+1<<" "<<x3+1;
    }
    if(x1==x3 && y1==y2){
        cout<<y3+1<<" "<<x2+1;
    }
    if(x2==x3 && y2==y1){
        cout<<y3+1<<" "<<x1+1;
    }
    if(x2==x1 && y2==y3){
        cout<<y1+1<<" "<<x3+1;
    }
    if(x3==x1 && y3==y2){
        cout<<y1+1<<" "<<x2+1;
    }
    if(x3==x2 && y3==y1){
        cout<<y2+1<<" "<<x1+1;
    }
    
}