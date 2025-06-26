#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long max_coins = 0;
    int index = 0;

    while (index < n) {
        int current_max = arr[index];

        // Traverse the array while the elements have the same sign
        while (index + 1 < n && (arr[index + 1] > 0) == (current_max > 0)) {
            current_max = max(current_max, arr[index + 1]);
            index++;
        }

        max_coins += current_max;
        index++;
    }

    cout << max_coins << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}
