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



void solve(){
    int n=1,m=0;
    string s;
    cin>>n;
    vector<vector<int>>adj(n);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool cond=false;
    for(auto x:adj){
        if(x.size()==2){
            cond=true;
            break;
        }
    }
    if(!cond){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

    queue<int>q;
    vector<bool>visited(n,false);
    int distance[n];
    visited[0]=true;
    distance[0]=0;
    q.push(0);
    bool switched=false;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        if(adj[s].size()==2 && !switched){
            switched=true;
            if(!visited[adj[s][0]]){
                if(!visited[adj[s][1]]){
                    visited[adj[s][1]]=true;
                    distance[adj[s][1]]=distance[s]+1;
                    q.push(adj[s][1]);
                    if(distance[s]%2==0)cout<<s+1<<" "<<adj[s][1]+1<<endl;
                    else cout<<adj[s][1]+1<<" "<<s+1<<endl;
                }
                distance[adj[s][0]]=distance[s];
                visited[adj[s][0]]=true;
                if(distance[s]%2==0)cout<<adj[s][0]+1<<" "<<s+1<<endl;
                else cout<<s+1<<" "<<adj[s][0]+1<<endl;
                q.push(adj[s][0]);
            }
            else{
                distance[adj[s][1]]=distance[s];
                visited[adj[s][1]]=true;
                if(distance[s]%2==0)cout<<adj[s][1]+1<<" "<<s+1<<endl;
                else cout<<s+1<<" "<<adj[s][1]+1<<endl;
                q.push(adj[s][1]);
            }
        }
        else{
            for(auto u:adj[s]){
                if(visited[u])continue;
                visited[u]=true;
                distance[u]=distance[s]+1;
                q.push(u);
                if(distance[s]%2==0)cout<<s+1<<" "<<u+1<<endl;
                else cout<<u+1<<" "<<s+1<<endl;
            }
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

    