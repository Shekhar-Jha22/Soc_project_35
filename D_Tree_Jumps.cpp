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

void dfs(int u, int l, vector<vector<int>>& adj, vector<vector<int>>& distances) {
    if (l >= distances.size()) distances.resize(l + 1);

    if (u == 1) {
        distances[l].push_back(0);
        for (auto x : adj[u]) {
            dfs(x, l + 1, adj, distances);
        }
    }
    else if (adj[u].size() == 0) {
        distances[l].push_back(u);
    }
    else {
        distances[l].push_back(u);
        for (auto x : adj[u]) {
            dfs(x, l + 1, adj, distances);
        }
    }
}

int sum(int u, int l, const vector<vector<int>>& adj, const vector<vector<int>>& distances) {
    if (adj[u-1].size() == 0 || (distances.size() <= l + 1) || distances[l + 1].size() - adj[u-1].size() == 0)
        return 1;

    if (u == 1) {
        int sum1 = 0;
        for (auto x : adj[u]) sum1 += sum(x, l + 1, adj, distances);
        return sum1+1;
    }
    else {
        int sum1 = 0, sum2 = 0;
        for (auto x : distances[l + 1]) {
            sum1 += sum(x, l + 1, adj, distances);
        }
        for (auto x : adj[u]) {
            sum2 += sum(x, l + 1, adj, distances);
        }
        return sum1 - sum2;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        adj[v[i] - 1].push_back(i + 1);
    }

    vector<vector<int>> distances;
    dfs(0, 0, adj, distances);

    cout << sum(0, 0, adj, distances) << endl;
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

    