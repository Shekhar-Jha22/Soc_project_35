#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 998244353;

long long sum_of_k_largest_products(vector<int>& arr) {
    sort(arr.begin(), arr.end());  // Sort in increasing order
    long long total_sum = 0;
    long long product = 1;

    // Compute the sum of products for k from 1 to n
    for (int k = 1; k <= arr.size(); k++) {
        product = (product * arr[arr.size() - k]) % MOD;  // Compute product dynamically
        total_sum = (total_sum + product) % MOD;  // Add to total sum
    }

    return total_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << sum_of_k_largest_products(arr) << '\n';
    }

    return 0;
}
