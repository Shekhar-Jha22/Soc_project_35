#include<iostream>
#include<string>

using namespace std;

int value(string a,string b,string c,int l1,int l2){
    if(l1==a.size() && l2==b.size())return 0;
    else if(l1==a.size()){
        if(b[l2]!=c[l1+l2])return value(a,b,c,l1,l2+1)+1;
        else return value(a,b,c,l1,l2+1);
    }
    else if(l2==b.size()){
        if(a[l1]!=c[l1+l2])return value(a,b,c,l1+1,l2)+1;
        else return value(a,b,c,l1+1,l2);
    }
    else{
        if(c[l1+l2]==a[l1] && c[l1+l2]==b[l2])return min(value(a,b,c,l1,l2+1),value(a,b,c,l1+1,l2));
        else if(c[l1+l2]==a[l1])return min(value(a,b,c,l1+1,l2),value(a,b,c,l1,l2+1)+1);
        else if(c[l1+l2]==b[l2])return min(value(a,b,c,l1+1,l2)+1,value(a,b,c,l1,l2+1));
        else return min(value(a,b,c,l1,l2+1),value(a,b,c,l1+1,l2))+1;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string a,b,c;
        cin>>a>>b>>c;
        cout<<value(a,b,c,0,0)<<endl;
    }
}