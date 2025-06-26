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

int solve1(int a, int b) {
    a--; b--;
    int num = 0;
    for (int i = 30; i >= 0; i--) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;

        // Lookup based on (bitA, bitB) pair
        int lookup[2][2] = {
            {0, 3},
            {2, 1}
        };
        int val = lookup[bitA][bitB];

        num += val * (1LL << (2 * i));
    }
    return num + 1;
}



pair<int, int> solve2(int a) {
    a--;
    int x = 0, y = 0, count = 0;
    while (a != 0) {
        int mod = a % 4;
        if (mod == 1) {
            x += (1LL << count);
            y += (1LL << count);
        } else if (mod == 2) {
            y += (1LL << count);
        } else if (mod == 3) {
            x += (1LL << count);
        }
        a /= 4;
        count++;
    }
    return {y + 1, x + 1};
}

void solve(){
    int n=1,m=0;
   
    cin>>n>>m;
    vector<pair<int,int>>v;
    fr(i,m){
        int a,b;
        char c1,c2;
        cin>>c1>>c2;
        if(c1=='-' && c2=='>'){
            cin>>a>>b;
            v.push_back({solve1(a,b),-1});
        }
        else{
            cin>>a;
            v.push_back(solve2(a));
        }
    }
    fr(i,m){
        if(v[i].second==-1)cout<<v[i].first<<endl;
        else cout<<v[i].first<<" "<<v[i].second<<endl;
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

    