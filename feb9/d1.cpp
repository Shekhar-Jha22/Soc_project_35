#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long compute_score(const vector<int>& arr) {
    long long sum = 0, total_score = 0;
    for (int num : arr) {
        sum += num;
        total_score += sum;
    }
    return total_score;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arrays(n, vector<int>(m));
    vector<long long> scores(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arrays[i][j];
        }
        sort(arrays[i].begin(), arrays[i].end());
        scores[i] = compute_score(arrays[i]);
    }
    
    sort(scores.rbegin(), scores.rend());
    
    long long max_score = 0, accumulated_sum = 0;
    for (long long score : scores) {
        accumulated_sum += score;
        max_score += accumulated_sum;
    }
    
    cout << max_score << endl;
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
