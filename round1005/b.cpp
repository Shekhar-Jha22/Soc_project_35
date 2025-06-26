#include <bits/stdc++.h>
using namespace std;
int l1=0,l2=0,r1=0,r2=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> freq;

    
    for (int &x : a) {
        cin >> x;
        freq[x]++;
    }

    int max_length = 0, best_l = -1, best_r = -1;
    int l = 0;

   
    for (int r = 0; r < n; ++r) {
        if (freq[a[r]] > 1) {
            
            l = r + 1;
        } 
        else {
            int length = r - l + 1;
            if (length > max_length) {
                max_length = length;
                best_l = l;
                best_r = r;
            }
        }
    }

   
    if (max_length == 0) {
        cout << "0"<<endl;
    } else {
        cout << best_l + 1 << " " << best_r + 1 << endl; 
    }
    }
    
}
