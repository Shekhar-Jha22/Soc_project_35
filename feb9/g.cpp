#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
vector<bool> is_prime(MAX_N + 1, true);
vector<int> primes;
unordered_set<int> semi_primes;

// Sieve of Eratosthenes to find prime numbers
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    // Compute all semi-primes
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i; j < primes.size(); ++j) {
            long long semi_prime = 1LL * primes[i] * primes[j];
            if (semi_prime > MAX_N) break;
            semi_primes.insert(semi_prime);
        }
    }
}

// Function to check if a number is a product of exactly two primes
bool is_product_of_two_primes(int num) {
    for (int prime : primes) {
        if (prime * prime > num) break;
        if (num % prime == 0 && is_prime[num / prime]) {
            return true;
        }
    }
    return false;
}

// Function to count valid pairs
long long count_valid_pairs(const vector<int>& a, int n) {
    vector<int> freq(MAX_N + 1, 0);
    for (int x : a) freq[x]++;

    long long count = 0;
    for (int x = 2; x <= MAX_N; ++x) {
        if (freq[x] == 0) continue;
        for (int y = x; y <= MAX_N; y += x) {
            if (freq[y] == 0) continue;
            int lcm_xy = (x / __gcd(x, y)) * y;
            if (lcm_xy <= MAX_N && semi_primes.count(lcm_xy)) {
                if (x == y)
                    count += 1LL * freq[x] * (freq[x] - 1) / 2;
                else
                    count += 1LL * freq[x] * freq[y];
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve(); // Precompute primes and semi-primes
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << count_valid_pairs(a, n) << "\n";
    }
    return 0;
}
