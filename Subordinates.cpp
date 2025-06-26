#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> adj[], vector<int>& memo) {
    // If already computed, return cached value
    if (memo[node] != -1) return memo[node];

    int count = 0;
    for (int child : adj[node]) {
        count += 1 + dfs(child - 1, adj, memo);  // count child + its subordinates
    }

    memo[node] = count;  // Memoize result
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        adj[x - 1].push_back(i + 2);
    }

    vector<int> memo(n, -1);  // -1 means not computed
    for (int i = 0; i < n; i++) {
        cout << dfs(i, adj, memo) << " ";
    }
    cout << endl;

    return 0;
}
