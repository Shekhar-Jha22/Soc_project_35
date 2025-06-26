#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> tree;
vector<int> a;
vector<int> result;
vector<int> subtree_size;
unordered_map<int, int> freq;

void dfs(int node, int parent) {
    subtree_size[node] = 1;
    
    for (int neighbor : tree[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
        subtree_size[node] += subtree_size[neighbor];
    }
}

bool check_majority(int node, int total_size) {
    unordered_map<int, int> count;
    vector<int> stack = {node};

    int max_freq = 0;
    while (!stack.empty()) {
        int curr = stack.back();
        stack.pop_back();
        count[a[curr]]++;
        max_freq = max(max_freq, count[a[curr]]);
        for (int neighbor : tree[curr]) {
            if (count.find(neighbor) == count.end()) {
                stack.push_back(neighbor);
            }
        }
    }
    return max_freq > total_size / 2;
}

void solve() {
    int n;
    cin >> n;

    tree.assign(n + 1, vector<int>());
    a.assign(n + 1, 0);
    result.assign(n + 1, 0);
    subtree_size.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        result[i] = check_majority(i, n) ? 1 : 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
