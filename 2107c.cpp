#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename Iterator>
int max_subarraysum(Iterator begin, Iterator end) {
    if (begin == end) return 0;

    int maxSum = *begin;
    int currSum = *begin;

    for (Iterator it = begin + 1; it != end; ++it) {
        currSum = max(*it, currSum + *it);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v(n);
        int count0 = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (s[i] == '0') count0++;
        }

        if (count0 == 0) {
            if (max_subarraysum(v.begin(), v.end()) != k) cout << "no" << endl;
            else cout << "yes" << endl;
            continue;
        }

        if (count0 == n) {
            cout << "yes" << endl;
            continue;
        }

        vector<vector<int>> v1;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                temp.push_back(v[i]);
            } else {
                if (!temp.empty()) {
                    v1.push_back(temp);
                    temp.clear();  // don't redeclare
                }
            }
        }

        // In case the last segment ends with '1'
        if (!temp.empty()) {
            v1.push_back(temp);
        }

        int maximum = max_subarraysum(v1[0].begin(), v1[0].end());
        for (int i = 1; i < v1.size(); i++) {
            maximum = max(maximum, max_subarraysum(v1[i].begin(), v1[i].end()));
        }

        if (maximum > k) cout << "no" << endl;
        else cout << "yes" << endl;
    }

    return 0;
}
