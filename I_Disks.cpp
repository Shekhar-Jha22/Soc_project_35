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

struct triple{
    int x, y, radius;
};

bool check_bipartite(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, -1);
    
    fr(i, n) {
        if(vis[i] == -1) {
            int sum = 0;
            vis[i] = 0;
            bool f = true;
            queue<int> q;
            q.push(i);
            
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                
                if(vis[x]) sum++;
                else sum--;
                
                fr(j, sz(adj[x])) {
                    int u = adj[x][j];
                    if(vis[u] == vis[x]) {
                        f = false;
                    }
                    else if(vis[u] == -1) {
                        vis[u] = vis[x] ^ 1;
                        q.push(u);
                    }
                }
            }
            
            if(f && sum != 0) return true;
        }
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<triple> v(n);
    
    fr(i, n) {
        cin >> v[i].x >> v[i].y >> v[i].radius;
    }
    
    vector<vector<int>> adj(n);
    
    fr(i, n) {
        fr(j, n) {
            int dx = v[i].x - v[j].x;
            int dy = v[i].y - v[j].y;
            int sum_r = v[i].radius + v[j].radius;
            if(dx * dx + dy * dy == sum_r * sum_r) {
                adj[i].push_back(j);
            }
        }
    }
    
    if(check_bipartite(n, adj)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}