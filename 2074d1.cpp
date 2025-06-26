#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;
#include<climits>
#include<set>


struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};


int countPointsInsideCircle(int cx, int r, unordered_set<pair<int, int>, pair_hash>& coveredPoints) {
    int count = 0,vall=0;

    for (int x = cx - r; x <= cx + r; x++) {
        int max_y = floor(sqrt(r * r - (x - cx) * (x - cx))); 
int foo=0;
        for (int y = -max_y; y <= max_y; y++) { 
            pair<int, int> point = {x, y};
            if (coveredPoints.find(point) == coveredPoints.end()) {
                coveredPoints.insert(point); 
                count++;
                foo++;
            }
        }
    }

    return count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n>>m;
        
        vector<int> rvec(n), xvec(n);
        // Read x-coordinates
        for (int i = 0; i < n; i++) {
            cin >> xvec[i];
        }
        // Read radii
        for (int i = 0; i < n; i++) {
            cin >> rvec[i];
        }
        

        unordered_set<pair<int, int>, pair_hash> coveredPoints;
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            total += countPointsInsideCircle(xvec[i], rvec[i], coveredPoints);
        }

        cout << total << endl;
    }

    return 0;
}
