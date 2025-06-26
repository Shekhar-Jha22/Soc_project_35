#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for(int &x : v) cin >> x;

    vector<int> adj[n+1];
    for(int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        adj[x].push_back(i + 2); // input is 1-indexed
    }

    // BFS to calculate depths
    vector<int> depth(n + 1, 0);
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int child : adj[u]) {
            depth[child] = depth[u] + 1;
            q.push(child);
        }
    }

    // Store nodes with their depths
    vector<pair<int, int>> nodes;
    for(int i = 1; i <= n; i++) {
        nodes.push_back({i, depth[i]});
    }

    // Sort in decreasing depth to process children before parents
    sort(nodes.begin(), nodes.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    // Update node values from leaves up
    for(auto [node, d] : nodes) {
        if(adj[node].empty() || node==1) continue; // leaf
        int minval = LLONG_MAX,child_min=INT64_MAX;

        for(int child : adj[node]) {
            child_min=min(child_min,v[child-1]);
            minval = min(minval, (v[node - 1] + v[child - 1]) / 2);
        }
        if(child_min<=v[node-1]){
            v[node-1]=child_min;
        }
        else
        v[node - 1] = minval;
    }
    int mi=INT64_MAX;
    for(int child : adj[1]) {
        mi=min(mi, v[child - 1]);
    }
    cout<<v[0]+mi<<endl;
}

int32_t main() {
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
  