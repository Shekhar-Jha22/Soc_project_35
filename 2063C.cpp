#include <bits/stdc++.h>
using namespace std;

// Function to check if the pattern "1100" exists
bool hasPattern(set<int>& indices) {
    return !indices.empty();
}

// Function to update pattern occurrences near the modified index
void updatePattern(string& s, set<int>& indices, int pos) {
    int l = s.size();
    
    // Ensure bounds checking
    for (int i = max(0, pos - 3); i <= min(l - 4, pos); i++) {
        if (i + 3 < l && s.substr(i, 4) == "1100") {
            indices.insert(i);
        } else {
            indices.erase(i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int n;
        cin >> n;

        set<int> patternIndices;
        int l = s.size();

        // Precompute initial positions of "1100"
        for (int i = 0; i <= l - 4; i++) {
            if (s.substr(i, 4) == "1100") {
                patternIndices.insert(i);
            }
        }

        while (n--) {
            int x, v;
            cin >> x >> v;
            
            // Ensure valid bounds (1-based input, convert to 0-based)
            if (x < 1 || x > l) continue;  
            
            s[x - 1] = v + '0'; // Update character
            
            // Update pattern occurrences near x-1
            updatePattern(s, patternIndices, x - 1);

            cout << (hasPattern(patternIndices) ? "yes" : "no") << endl;
            
        }
    }
    return 0;
}
