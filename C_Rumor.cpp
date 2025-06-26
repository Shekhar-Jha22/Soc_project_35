#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> parent, min_val;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return; // Already in same component
    
    // Union by making one parent of other and updating minimum
    parent[b] = a;
    min_val[a] = min(min_val[a], min_val[b]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    parent.resize(n);
    min_val.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> min_val[i];
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        unite(a, b);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) { // This is a root node
            sum += min_val[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}