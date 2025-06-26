#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> perm(n + 1);  // 1-based indexing
        for (int i = 1; i <= n; ++i)
            cin >> perm[i];

        vector<vector<int>> cycles;
        vector<bool> visited(n + 1, false);
        unordered_map<int, int> elementToCycleSize;
        unordered_map<int, int> cycleRepresentative;

        // Step 1: Detect cycles
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                vector<int> cycle;
                int curr = i;
                while (!visited[curr]) {
                    visited[curr] = true;
                    cycle.push_back(curr);
                    curr = perm[curr];
                }

                int rep = cycle[0];  // Choose a representative for this cycle
                for (int x : cycle) {
                    elementToCycleSize[x] = cycle.size();
                    cycleRepresentative[x] = rep;
                }

                cycles.push_back(cycle);
            }
        }

        // Step 2: Read queries
        vector<int> queries(n);
        for (int i = 0; i < n; ++i)
            cin >> queries[i];

        // Step 3: Answer queries
        unordered_map<int, bool> visitedCycle;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int val = queries[i];
            int rep = cycleRepresentative[val];

            if (!visitedCycle[rep]) {
                sum += elementToCycleSize[val];
                visitedCycle[rep] = true;
            }

            cout << sum << " ";
        }

        cout << endl;
    }

    return 0;
}
