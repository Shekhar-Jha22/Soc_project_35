#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int T;
    cin >> T;
    while (T--) {
        long long int n, l, r;
        cin >> n >> l >> r;

        vector<long long int> v(n);
        for (long long int i = 0; i < n; i++) {
            cin >> v[i];
        }

        // Fixing sorting issues
        if (l > 1) sort(v.begin(), v.begin() + l - 1); // Sorting from index 0 to l-2
        sort(v.begin() + l - 1, v.begin() + r);        // Sorting from l-1 to r-1
        if (r < n) sort(v.begin() + r, v.end());       // Sorting from r to n-1

        long long int sum1 = 0, sum2 = 0;

        for (long long int i = 0; i < r - l + 1; i++) {
            if(i<l-1){
                if(v[i]<v[r-1-i])sum1+=v[i];
                else sum1+=v[r-1-i];
            }
            else sum1+=v[r-1-i];

            if(r+i<n){
                if(v[r+i]<v[r-1-i])sum2+=v[r+i];
                 else sum2+=v[r-1-i];
            }
             else sum2+=v[r-1-i];
        }

        cout << min(sum1, sum2) << endl;
    }
    return 0;
}
