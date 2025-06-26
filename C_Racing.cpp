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

bool check(int n, const vector<vector<int>>& possibilities, const vector<int>& d) {
    int low = 0, high = 0;  // initial height range at h₀ = 0

    for (int i = 0; i < n; ++i) {
        int min_next, max_next;

        if (d[i] == 0) {
            min_next = low;
            max_next = high;
        } else if (d[i] == 1) {
            min_next = low + 1;
            max_next = high + 1;
        } else { // d[i] == -1 → could be 0 or 1
            min_next = low;
            max_next = high + 1;
        }

        // Clamp to current obstacle's bounds
        int obs_low = possibilities[i][0];
        int obs_high = possibilities[i][1];

        low = max(min_next, obs_low);
        high = min(max_next, obs_high);

        if (low > high) return false;  // No valid height possible at this step
    }

    return true;  // Valid path exists
}


vector<int> fix_path(vector<vector<int>> arr, vector<int>& d, int n) {
    vector<int> lo(n + 1), hi(n + 1);
    lo[0] = hi[0] = 0;

    // Forward pass: determine valid height ranges
    for (int i = 1; i <= n; ++i) {
        if (d[i - 1] == 0) {
            lo[i] = lo[i - 1];
            hi[i] = hi[i - 1];
        } else if (d[i - 1] == 1) {
            lo[i] = lo[i - 1] + 1;
            hi[i] = hi[i - 1] + 1;
        } else { // d[i-1] == -1
            lo[i] = lo[i - 1];
            hi[i] = hi[i - 1] + 1;
        }

        lo[i] = max(lo[i], arr[i - 1][0]);
        hi[i] = min(hi[i], arr[i - 1][1]);

        if (lo[i] > hi[i]) return {}; // No valid path
    }

    // Backward pass: reconstruct with greedy preference for 1s
    vector<int> result = d;
    int h = lo[n];

    for (int i = n - 1; i >= 0; --i) {
        if (d[i] == 0) {
            // stay → h remains
        } else if (d[i] == 1) {
            h -= 1;
        } else {
            // Try 1 first
            if (h - 1 >= lo[i] && h - 1 <= hi[i]) {
                result[i] = 1;
                h -= 1;
            } else if (h >= lo[i] && h <= hi[i]) {
                result[i] = 0;
                // h stays the same
            } else {
                return {}; // invalid backtrack
            }
        }
    }

    return result;
}




void solve(){
    int n=1;
    
    cin>>n;
    vi v(n);
    fr(i,n)cin>>v[i];

    vector<vector<int>> arr(n);
    fr(i,n){
        int a,b;
        cin>>a>>b;

        arr[i].push_back(a);
        arr[i].push_back(b);
    }

    vector<vector<int>> possibilities(n);
    int low=0,high=0;
    fr(i,n){
        if(v[i]==1){
            high++;
            low++;
        }
        else if(v[i]==-1){
            high++;
            
        }
        low=max(low,arr[i][0]);
        high=min(high,arr[i][1]);
        possibilities[i].push_back(low);
        possibilities[i].push_back(high);
    }
    
    bool cond=check(n,possibilities,v);
    
    if(!cond)cout<<-1<<endl;
    else {
        vi pathfound=fix_path(possibilities,v,n);
        for(auto x:pathfound)cout<<x<<" ";
        cout<<endl;
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

    