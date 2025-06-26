#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> pairs; // {sum of 1s, original index}
        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            cin >> matrix[i];
            int sum = count(matrix[i].begin(), matrix[i].end(), '1');
            pairs.push_back({sum, i}); // Store {sum of 1s, 0-based index}
        }

        // Sorting using a lambda function
        sort(pairs.begin(), pairs.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
           
                // Ensure index is within valid range before accessing matrix
                if (a.second < n && b.second < n) {
                    return matrix[a.second][b.second] != '1';
                }
                return false; // Fallback in case of an out-of-bounds error
            
            
        });

        // Output the sorted 1-based indices
        for (auto x : pairs) {
            cout << x.second + 1 << " "; // Convert back to 1-based index
        }
        cout << endl;
    }

    return 0;
}
