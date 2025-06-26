#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0];  // Compare the first element of each vector
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        bool cond=true;
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v;
         vector<vector<int>>v2;

        for(int i=0;i<n;i++){
            vector<int>v1;
            for(int j=0;j<m;j++){
                int x;
                cin>>x;
                v1.push_back(x);

            }
            sort(v1.begin(),v1.end());
            v.push_back(v1);
            v1.erase(v1.begin(),v1.end());
        }
        v2=v;
        sort(v.begin(),v.end(),compare);
        int current=-1,prev=-1;
        for(int j=0;j<m;j++){
            int k;
            for( k=0;k<n;k++){
                if( k==0)current=v[k][j];
                else {
                    prev=current;
                    current =v[k][j];
                }
                if(current<prev){
                    cout<<-1<<endl;
                    break;
                }    
            }
            if(current<prev){
                    cond=false;
                    break;
                }    
            if (k==n)k=0;
        }
        if(cond){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(v2[j][0]==v[i][0]){
                        cout<<j+1<<" ";
                        break;
                        }
                }
            }
            cout<<endl;
        }

    }
}