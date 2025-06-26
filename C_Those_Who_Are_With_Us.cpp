#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<int> v1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            v1.push_back(v[i][j]);
        }
    }
    
    sort(v1.begin(), v1.end());
    int max1 = v1[n*m-1], max2 = v1[n*m-2];
    
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    bool found_max1 = false;
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == max1 && !found_max1){
                x1 = i;
                y1 = j;
                found_max1 = true;
            }
            else if(v[i][j] == max2 && (x2 == -1 || y2 == -1)){
                x2 = i;
                y2 = j;
            }
        }
    }
    
    if(x1 != x2 && y1 != y2){
       
        vector<vector<int>> temp1 = v;
        vector<vector<int>> temp2 = v;
        
      
        for(int i = 0; i < n; i++) temp1[i][y1]--;
        for(int j = 0; j < m; j++){
            if(j != y1) temp1[x2][j]--;
        }
        
       
        for(int i = 0; i < n; i++) temp2[i][y2]--;
        for(int j = 0; j < m; j++){
            if(j != y2) temp2[x1][j]--;
        }
        
        int maxval1 = 0, maxval2 = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxval1 = max(maxval1, temp1[i][j]);
                maxval2 = max(maxval2, temp2[i][j]);
            }
        }
        
        cout << min(maxval1, maxval2) << endl;
    }
    else if(x1 == x2){
       
        int best_col = 0, max_in_col = 0;
        for(int j = 0; j < m; j++){
            
                for(int i = 0; i < n; i++){
                    if(i != x1 && v[i][j] > max_in_col){
                        max_in_col = v[i][j];
                        best_col = j;
                    }
                
            }
        }
        
        vector<vector<int>> temp = v;
        
        for(int i = 0; i < n; i++) temp[i][best_col]--;
        
        for(int j = 0; j < m; j++){
            if(j != best_col) temp[x1][j]--;
        }
        
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result = max(result, temp[i][j]);
            }
        }
        cout << result << endl;
    }
    else{
        
        int best_row = 0, max_in_row = 0;
        for(int i = 0; i < n; i++){
            
                for(int j = 0; j < m; j++){
                    if(j != y1 && v[i][j] > max_in_row){
                        max_in_row = v[i][j];
                        best_row = i;
                    }
                }
            
        }
        
        vector<vector<int>> temp = v;
       
        for(int j = 0; j < m; j++) temp[best_row][j]--;
       
        for(int i = 0; i < n; i++){
            if(i != best_row) temp[i][y1]--;
        }
        
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result = max(result, temp[i][j]);
            }
        }
        cout << result << endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}