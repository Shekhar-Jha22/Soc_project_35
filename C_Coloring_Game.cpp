#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countValidTriplets(vector<int>& arr) {
    int n = arr.size();
    int maxElement = arr[n-1]; 
    long long count = 0;
    
   
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = arr[i];
            int b = arr[j];
           
            long long minVal = (long long)maxElement - a - b + 1;
            long long maxVal = (long long)a + b - 1;
            
           
            if (minVal > maxVal) continue;
            
          
            int left = lower_bound(arr.begin() + j + 1, arr.end(), minVal) - arr.begin();
            
            
            int right = upper_bound(arr.begin(), arr.end(), maxVal) - arr.begin() - 1;
            
            
            if (left <= right && left < n) {
                count += max(0, min(right, n-1) - left + 1);
            }
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        cout << countValidTriplets(a) << "\n";
    }
    
    return 0;
}