#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];

        // Compute prefix and suffix GCD arrays
        vector<int> prefixGCD(n), suffixGCD(n);
        
        prefixGCD[0] = v[0];
        for (int i = 1; i < n; i++) 
            prefixGCD[i] = gcd(prefixGCD[i - 1], v[i]);

        suffixGCD[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) 
            suffixGCD[i] = gcd(suffixGCD[i + 1], v[i]);

        // Compute the maximum GCD when removing one element
        int maxGCD = suffixGCD[1]; // If we remove v[0]
        for (int i = 1; i < n - 1; i++) 
            maxGCD = max(maxGCD, gcd(prefixGCD[i - 1], suffixGCD[i + 1]));

        maxGCD = max(maxGCD, prefixGCD[n - 2]); // If we remove v[n-1]
        
        cout << maxGCD << '\n';
    }
}
