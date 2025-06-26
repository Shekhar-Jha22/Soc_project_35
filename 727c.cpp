#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    cout<<"? 1 3"<<endl;
    fflush(stdout);
    int sum1=0;
    cin>>sum1;
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    int sum2=0;
    cin>>sum2;
    cout<<"? 2 3"<<endl;
    fflush(stdout);
    int sum3=0;
    cin>>sum3;
    v[1]=(sum2+sum3-sum1)/2;
    v[0]=(sum2+sum1-sum3)/2;
    v[2]=(sum1+sum3-sum2)/2;
    for(int i=0;i<n-3;i++){
        cout<<"? "<<3+i<<" "<<4+i<<endl;
        fflush(stdout);
        int val;
        cin>>val;
        v[3+i]=val-v[2+i];
    }
    cout<<"! ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}