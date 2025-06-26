#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        vector<int>a1;
        vector<int>b1;
        for(int i=0;i<a;i++){
            int x;
            cin>>x;
            a1.push_back(x);
        }
        for(int i=0;i<b;i++){
            int x;
            cin>>x;
            b1.push_back(x);
        }
        int aleft=0,aright=a-1,bleft=0,bright=b-1;
        for(int i=0;i<a;i++){
            if(aleft>aright)break;
            if(a1[aleft]>=b1[bleft]){

                aleft++;
                bleft++;
            }
            else if(a1[aright]>=b1[bright]){
                aright--;
                bright--;
            }
            else {
                aleft++;
                aright--;
            }
        }
    }
}