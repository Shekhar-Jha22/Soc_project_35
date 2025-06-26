#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        
        
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            vector<int>v1;
            for(int i=0;i<n;i++){
                int x;
                cin>>x;
                v1.push_back(x);
            }
            reverse(v1.begin(),v1.end());
            v.push_back(v1);
        }
        sort(v.begin(),v.end());
        vector<int>v1s;
        for(int i=0;i<n;i++){
            int count=0;
            
            for(int j=1;j<n;j++){
                if(v[i][j]==1 ){
                    count++;
                    
                }
                else break;
          
            }
            v1s.push_back(count);
        }
        sort(v1s.begin(),v1s.end());

        unordered_map<int,int>mp;

        
        int counts=0;

        for(int i=0;i<v1s.size();i++){
            if(mp[v1s[i]])mp[v1s[i]]++;
            else mp[v1s[i]]=1;
        }
        for(int i=0;i<v1s.size();i++){
           if(mp[0]==0){
            for(int i=1;i<n;i++){
                if(mp[i]>1){
                    mp[0]=1;
                    mp[i]--;
                    counts++;
                    break;
                }
                
            }
            if(mp[0]==1)continue;
            if(mp[0]==0){
                mp[v1s.back()]=0;
                mp[0]=1;
                counts++;
                continue;
            }
           }
           else if(mp[i]==counts){
            counts++;
            continue;
           }
           else if(mp[i]==counts-1)continue;
           else break;
        }

        cout<<counts<<endl;
    }
}