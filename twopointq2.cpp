#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>A,B;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    int a=0;
    for(int i=0;i<m;i++){
        if(a==n){
            cout<<n<<" ";
        }
        else {
            while(B[i]>A[a]){
                if(a==n)break;
                a++;
            }
            cout<<a<<" ";
        }
    }
}