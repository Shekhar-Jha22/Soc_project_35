#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int posn=0,count0=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='1'){
                posn=i;
                break;
            }
        }
        for(int i=posn;i<s.size();i++){
            if(s[i]!='0')break;
            else count0++;
        }
        if(posn==0){
            cout<<1<<" "<<s.size()<<" "<<1<<" "<<1<<endl;
        }
        else if(count0>=posn)cout<<1<<" "<<s.size()<<" "<<1<<" "<<s.size()-posn<<endl;
        else cout<<1<<" "<<s.size()<<" "<<posn-count0+1<<" "<<posn-count0+s.size()-posn<<endl;
        
       
    }
}