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


int solve_gold_blast(vector<string>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    
 
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int gold_value = (grid[i-1][j-1] == 'g') ? 1 : 0;
            prefix[i][j] = gold_value + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    auto get_gold_in_rectangle = [&](int r1, int c1, int r2, int c2) -> int {
        // Handle out of bounds by calculating valid intersection
        r1 = max(0LL, r1);
        c1 = max(0LL, c1);

        //khashdsn
        r2 = min(n-1, r2);
        c2 = min(m-1, c2);
        
        if (r1 > r2 || c1 > c2) {
            return 0;
        }
        
        // Convert to 1-indexed for prefix sum
        return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
    };
    
    vector<int> blast_golds;
    int radius = k - 1;  // Distance from center to edge
    
    // For each empty cell, calculate gold in its blast square
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {  // Empty cell
                // Calculate bounds of the square centered at (i,j)
                int r1 = i - radius;
                int c1 = j - radius;
                //jsadhjbwhdb
                int r2 = i + radius;
                int c2 = j + radius;
                
                int gold_in_blast = get_gold_in_rectangle(r1, c1, r2, c2);
                //jjdswbb
                int val=0;
                blast_golds.push_back(gold_in_blast);
            }
        }
    }
    
    // Sort and return minimum
    if (blast_golds.empty()) return 0;
    sort(blast_golds.begin(), blast_golds.end());
    //djbkhadj
    return blast_golds[0];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        //wbdjbwhh b
    int n, m;
    cin >> n >> m;
    int k,gold=0;
    cin >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(grid[i][j]=='g')gold++;
    }
    
    int result = solve_gold_blast(grid, k);
    cout << gold-result << endl;
    }
    return 0;
}