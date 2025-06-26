#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        cout<<"? "<<1<<" "<<n<<endl;
        fflush(stdout);
        int n1;
        cin>>n1;
        cout<<"? "<<n<<" "<<1<<endl;
        fflush(stdout);
        int n2;
        cin>>n2;
        if(n1==n2)cout<<"! B"<<endl;
        else cout<<"! A"<<endl;
    }
}