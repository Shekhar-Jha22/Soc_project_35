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
int MOD=998244353;      // Hardcoded, directly change from here for functions!



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
    vi v(n);
    cin>>v;
    vector<int>left1(n,0);
    vector<int>right3(n,0);
    vector<int>prefix3(n,0);
    vector<int>threes(n,0);
    for(int i=1;i<n;i++){
        if(v[i-1]==1)left1[i]=left1[i-1]+1;
        else left1[i]=left1[i-1];
    }
    for(int i=n-2;i>=0;i--){
        if(v[i+1]==3)right3[i]=right3[i+1]+1;
        else right3[i]=right3[i+1];
    }
    int sum=0;
    for(int i=n-2;i>0;i--){
        if(v[i]==2){
            threes[i]=(right3[i]+prefix3[i+1])%MOD;
            prefix3[i]=(prefix3[i+1]+threes[i])%MOD;
            sum=(((left1[i]*threes[i])%MOD)+sum+MOD)%MOD;
        }
        else {
            threes[i]=threes[i+1];
            prefix3[i]=prefix3[i+1];
        }
    }
    cout<<sum<<endl;
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

    