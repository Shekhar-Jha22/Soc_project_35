#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> v; // {row_number, count_of_1s}

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int count = 0;

            for (char c : s) {
                if (c == '1') count++;
            }

            v.push_back({i + 1, count});
        }

        // Sort by count ascending, then by row number descending
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first; // descending index
        });

        for (auto& p : v) {
            cout << p.first << " ";
        }
        cout << endl;
    }

    return 0;
}