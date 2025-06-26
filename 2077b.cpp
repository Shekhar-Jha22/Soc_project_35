#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        int x=k%2;
        if(x==0){
            for(int i=1;i<n-1;i++){
                cout<<n-1<<" ";
            }
            cout<<n<<" ";
            cout<<n-1<<" ";
        }
        else {
            for(int i=1;i<n-1;i++){
                cout<<n<<" ";
            }
            cout<<n<<" ";
            cout<<n-1<<" ";
        }
        cout<<endl;

    }
}