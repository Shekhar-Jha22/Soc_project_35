
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        int maxVal = 0;  

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            maxVal = max({maxVal, v[i].first, v[i].second});
        }
        
        vector<int> freq(maxVal + 2, 0);  // Extend by 1 for safety
        for (int i = 0; i < n; i++) {
            if (v[i].first == v[i].second) {
                freq[v[i].first]++;
            }
        }
        
        // Compute prefix sum for quick range queries
        vector<int> prefixSum(maxVal + 2, 0);
        for (int i = 1; i <= maxVal; i++) {
            prefixSum[i] = prefixSum[i - 1] + (freq[i] > 0 ? 1 : 0);
        }

        for (int i = 0; i < n; i++) {
            if (v[i].first == v[i].second) {
                cout << (freq[v[i].first] > 1 ? 0 : 1);
            } else {
                // Check range [first, second] in O(1) using prefix sum
                int countInRange = prefixSum[v[i].second] - prefixSum[v[i].first - 1];
                int rangeSize = v[i].second - v[i].first + 1;
                cout << (countInRange < rangeSize ? 1 : 0);
            }
        }
        cout << '\n';
    }

    return 0;
}
