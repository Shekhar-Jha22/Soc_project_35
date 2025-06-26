#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                a[i][j]=x;
            }
        }
        int val[2*n],sum=0;
        for(int i=1;i<2*n;i++){
            if(i<=n)val[i]=a[0][i-1];
            else val[i]=a[i-n][n-1];
            sum+=val[i];
        }
        val[0]=2*n*n+n-sum;
        for(auto x:val){
            cout<<x<<" ";

        }
        cout<<endl;
    }
}