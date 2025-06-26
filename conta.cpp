#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int count = 0;
    map<int, int> freq; // Ordered map to store frequencies
    int left = 0, uniqueCount = 0, maxFreq = 0;

    for (int right = 0; right < n; right++) {
        // Expand the window to the right
        freq[v[right]]++;

        // If this is a new unique element, increase unique count
        if (freq[v[right]] == 1) uniqueCount++;

        // Update max frequency
        maxFreq = max(maxFreq, freq[v[right]]);

        // Shrink the window if maxFreq > uniqueCount
        while (maxFreq > uniqueCount) {
            freq[v[left]]--; // Reduce frequency of the leftmost element
            
            // If freq becomes 0, remove element & decrease unique count
            if (freq[v[left]] == 0) {
                uniqueCount--;
                freq.erase(v[left]); // Remove from map
            }
            
            left++;

            // Recalculate maxFreq correctly
            if (!freq.empty()) {
                maxFreq = max_element(freq.begin(), freq.end(),
                                      [](const pair<int, int>& a, const pair<int, int>& b) {
                                          return a.second < b.second;
                                      })->second;
            } else {
                maxFreq = 0;
            }
        }

        // Add the number of valid subarrays ending at `right`
        count += (right - left + 1);
    }

    cout << count << endl;
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


