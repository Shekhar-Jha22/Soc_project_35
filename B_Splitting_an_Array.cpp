#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isValid(const vector<int>& v, int k, int maxAllowed) {
    int count = 1;  // start with 1 partition
    int sum = 0;
    for (int val : v) {
        if (val > maxAllowed) return false; // single element exceeds bound
        if (sum + val > maxAllowed) {
            count++;
            sum = val;
        } else {
            sum += val;
        }
    }
    return count <= k;
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int sum = 0, maxElem = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        maxElem = max(maxElem, v[i]);
    }

    int l = maxElem, r = sum, ans = sum;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isValid(v, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
