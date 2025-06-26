#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    
    set<int> reachable_set;
    reachable_set.insert(0);
    
    for (int i = 0; i < n; ++i) {
        vector<int> new_vals;
        for (int x : reachable_set) {
            new_vals.push_back(x + v[i]);
        }
        for (int x : new_vals) {
            reachable_set.insert(x);
        }
    }
    
    vector<int> reachable(reachable_set.begin(), reachable_set.end());
    
    int x = 0, count = 0;
    set<int> visited; // Track visited positions to avoid infinite loops
    
    while (true) {
        // Find the highest floor we can reach with current fuel
        auto it = upper_bound(reachable.begin(), reachable.end(), x + t);
        if (it == reachable.begin()) break; // No reachable floor
        
        --it; // Move to the largest reachable value
        int next_floor = *it;
        
        // If we can't make progress or we've been here before, stop
        if (next_floor <= x || visited.count(next_floor)) break;
        
        visited.insert(x); // Mark current position as visited
        x = next_floor;
        count++;
    }
    
    cout << count << endl;
    return 0;
}