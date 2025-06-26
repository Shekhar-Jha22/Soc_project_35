#include <iostream>
#include <bitset>

using namespace std;

string toBinaryString(int num) {
    return bitset<32>(num).to_string();  // Convert to 32-bit binary string
}

char convert(char c){
    if(c=='0')return'1';
    else return '0';
}

int main() {
    int x, y;
    cin >> x >> y;

   string s1=toBinaryString(x),s2=toBinaryString(y);
   reverse(s1.begin(),s1.end());
   reverse(s2.begin(),s2.end());

   for(int i=0;i<s1.size();){
        if(s1[i]-'0'==1 && s2[i]-'0'==1){
            
        }
   }
   
    return 0;
}
