#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
using namespace std;


void findPrimes(int n, std::vector<int>& primes) {
    if (n <= 2) return;

    std::vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>primes;
        findPrimes(2000000,primes);

        vector<pair<int,bool>>v;
        for(int i=0;i<n;i++){
            v[i].first=i+1;
            v[i].second=true;
        }
        vector<int>result;
        if(n%2==1){
            result[n/2]=1;
            v[0].second=false;
        }
        int x=n-1,y=primes.size()-1;
        while(x>=0){
            if(primes[y]>)
        }

    }
    
}