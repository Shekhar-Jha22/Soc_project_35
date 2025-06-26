#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double n,k;
        cin>>n>>k;
        bool found=false;
        vector<int> first_k;
        unordered_map<int,int>firstk;
        for(int i=0;i<k;i++){
            cout<<"? "<<i<<endl;
            cout.flush();
            int x;
            cin>>x;
            if(firstk[x]==1){
                cout<<i<<endl;
                found=true;
                break;
            }
            else{
                first_k.push_back(x);
                firstk[x]=1;
            }
            if(found)break;
            else {
                for(int i=1;i<ceil(n/k);i++){
                    cout<<"? "<<i*k<<endl;
                    cout.flush();
                    int x;
                    cin>>x;
                }
            }
        }
    }
}