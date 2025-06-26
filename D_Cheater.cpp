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
    vi me(n);
    cin>>me;
    vi dealer(n,0);
    cin>>dealer;
    int ind1=0,ind2=0;
    bool swapped=false;
    int score1=0,score2=0;
    for(int i=0;i<2*n;i++){
        if(ind1==n-1 || ind2==n-1)break;
        if(me[ind1]>dealer[ind2]){
            score1++;
            ind1++;
        }
        else if(ind1<n-1 && ind2<n-1 && me[ind1]<dealer[ind2] && me[ind1+1]>dealer[ind2] && me[ind1]>dealer[ind2+1] && !swapped){
            score1+=2;
            ind1+=2;
            ind2+=2;
            swapped=true;
        }
        else{
            ind2++;
        }
    }
    ind1=0,ind2=0;
    swapped=false;
    for(int i=0;i<2*n;i++){
        if(ind1==n-1 || ind2==n-1)break;
        if(me[ind1]>dealer[ind2]){
            score2++;
            ind1++;
        }
        else if(ind1<n-1 && me[ind1]<dealer[ind2] && me[ind1+1]>dealer[ind2] && !swapped){
            swap(me[ind1],me[ind1+1]);
            score2+=1;
            ind1+=1;
            ind2+=1;
            swapped=true;
        }
        else{
            ind2++;
        }
    }
    cout<<max(score1,score2)<<endl;
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

    