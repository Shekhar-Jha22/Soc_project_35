#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAX_N = 20000000;
bitset<MAX_N + 1> is_prime;
vector<int> prime_count(MAX_N + 1);

// Precompute number of primes up to i
void precompute_prime_counts() {
    is_prime.set();  // Set all to true initially
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= MAX_N; ++i) {
        if (is_prime[i]) count++;
        prime_count[i] = count;
    }
}

int primes_up_to(int n) {
    if (n > MAX_N) return prime_count[MAX_N];
    return prime_count[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_prime_counts();

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        int sum = 0;
        for (int i = 1; i <= x / 2; ++i) {
            int div = x / i;
            sum += primes_up_to(div);
        }
        cout << sum << '\n';
    }

    return 0;
}

