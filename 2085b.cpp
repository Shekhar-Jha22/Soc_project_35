#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v,zero;
        int nz1=n,nz2=n,zeroes=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x==0)zero.push_back(i);
            v.push_back(x);
            if(x==0)zeroes++;
            if(x!=0 && nz1==n)nz1=i;
            if(x!=0 && nz1!=n && nz2==n)nz2=i;
        }
    
        if(zeroes==0){
            cout<<1<<endl;
            cout<<1<<" "<<n<<endl;
        }
        else if(zeroes==n){
            cout<<3<<endl;
            cout<<1<<" "<<n-2<<endl;
            cout<<2<<" "<<3<<endl;
            cout<<1<<" "<<2<<endl;
        }
        else if(zero.size()==1){
            if(zero[0]==0 || zero[0]==1){
                cout<<2<<endl;
                cout<<1<<" "<<2<<endl;
                
                cout<<1<<" "<<n-1<<endl;
            }
            else if(zero[0]==n-1 || zero[0]==n-2){
                cout<<2<<endl;
                
                cout<<n-1<<" "<<n<<endl;
                cout<<1<<" "<<n-1<<endl;
            }
            else {
                cout<<2<<endl;
                cout<<1<<" "<<zero[0]+1<<endl;
                
                cout<<1<<" "<<n-zero[0]<<endl;
            }
        }
        else if(zero.size()==2){
            if(zero[0]==0 && zero[1]==1){
                cout<<2<<endl;
                cout<<1<<" "<<2<<endl;
                cout<<1<<" "<<n-1<<endl;
            }
            else if(zero[0]==n-2 && zero[1]==n-1){
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
                cout<<1<<" "<<n-1<<endl;
            }
            else if(zero[0]==0){
                cout<<3<<endl;
                cout<<1<<" "<<2<<endl;
                cout<<2<<" "<<n-1<<endl;
                cout<<1<<" "<<2<<endl;
            }
            else {
                cout<<3<<endl;
                cout<<1<<" "<<zero[0]+1<<endl;
                cout<<2<<" "<<n-zero[0]<<endl;
                cout<<1<<" "<<2<<endl;
            }
        }
        else if(zero.size()>2){
            if(zero[0]==0 && zero[1]==1){
                cout<<3<<endl;
                cout<<1<<" "<<2<<endl;
                cout<<2<<" "<<n-1<<endl;
                cout<<1<<" "<<2<<endl;
            }
            else if(zero[zero.size()-2]==n-2 && zero[zero.size()-1]==n-1){
                cout<<3<<endl;
                cout<<n-1<<" "<<n<<endl;
                cout<<1<<" "<<n-2<<endl;
                cout<<1<<" "<<2<<endl;
            }
            else if(zero[0]==0){
                cout<<3<<endl;
                cout<<1<<" "<<2<<endl;
                cout<<2<<" "<<n-1<<endl;
                cout<<1<<" "<<2<<endl;
            }
            else {
                cout<<3<<endl;
                cout<<1<<" "<<zero[0]+1<<endl;
                cout<<2<<" "<<n-zero[0]<<endl;
                cout<<1<<" "<<2<<endl;
            }
        }
    }
}