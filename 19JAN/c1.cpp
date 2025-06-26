#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

std::vector<std::pair<int, int>> findDistinctPairs(const std::vector<int>& arr, int k) {
    std::vector<std::pair<int, int>> result;
    std::unordered_set<int> seen;  
    
   
    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());
    
    int left = 0, right = sorted_arr.size() - 1;
    
    while (left < right) {
        int sum = sorted_arr[left] + sorted_arr[right];
        
        if (sum == k) {
            
            if (seen.find(sorted_arr[left]) == seen.end() && seen.find(sorted_arr[right]) == seen.end()) {
                result.push_back({sorted_arr[left], sorted_arr[right]});
                seen.insert(sorted_arr[left]);
                seen.insert(sorted_arr[right]);
            }
            
            left++;
            right--;
        } else if (sum < k) {
            left++;  
        } else {
            right--; 
        }
    }
    
    return result;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;

        vector<int >v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
    }

}
