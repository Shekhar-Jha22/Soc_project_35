#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================



int power(int a, int b) {
    int result = 1;
    a %= MOD;  // Handle large base
    while (b > 0) {
        if (b & 1) {
            result = (1LL * result * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return result;
}


void solve(){
    int n=1,m=0;
    string s;
    cin>>n;
    vector<int>adj[n];

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
    }

    vector<int>distance(n,0);
    vector<bool>visited(n,false);
    queue<int>q;

    q.push(1);
    visited[0]=true;
    distance[0]=0;

    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(auto u:adj[s-1]){
            if(visited[u-1])continue;
            visited[u-1]=true;
            distance[u-1]=distance[s-1]+1;
            q.push(u);
        }
    }

    int count=0,count1=0;
    for(int i=0;i<n;i++){
        if(adj[i].size()>3){
            cout<<0<<endl;
            return;
        }
        if(adj[i].size()==3)count++;
        if(adj[i].size()==1 && i!=0)count1++;
    }
    if(count>1 || count1>2){
        cout<<0<<endl;
        return;
    }
    else if(count==0 && adj[0].size()==1){
        cout<<power(2,n)<<endl;
        return;
    }
    else if(count==0 && adj[0].size()==2){
        int depth=0;
        int depth1=-1,depth2;
        
        for(int i=0;i<n;i++){
            
            if(adj[i].size()==1 && distance[i]>depth ){
                if(depth1==-1)depth1=distance[i]-depth;
                else depth2=distance[i]-depth;
            }
        }
        if(depth1==depth2){
            cout<<power(2,n-2*depth1+1)<<endl;
        }
        else{
            cout<<power(2,n-2*min(depth1,depth2))+power(2,n-2*min(depth1,depth2)-1)<<endl;
        }
    }
    else{
        int depth;
        int depth1=-1,depth2;
        for(int i=0;i<n;i++)if(adj[i].size()>2){
            depth=distance[i];
            break;
        }
        for(int i=0;i<n;i++){
            
            if(adj[i].size()==1 && distance[i]>depth ){
                if(depth1==-1)depth1=distance[i]-depth;
                else depth2=distance[i]-depth;
            }
        }
        if(depth1==depth2){
            cout<<power(2,n-2*depth1+1)<<endl;
        }
        else{
            cout<<power(2,n-2*min(depth1,depth2))+power(2,n-2*min(depth1,depth2)-1)<<endl;
        }

    }
    
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    