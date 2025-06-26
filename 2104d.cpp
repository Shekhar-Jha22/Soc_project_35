#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 4e5;  // Enough to cover all t cases

vector<int> prime;

bool is_prime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void generate_primes(int limit) {
    int current = 2;
    while ((int)prime.size() < limit) {
        if (is_prime(current)) {
            prime.push_back(current);
        }
        current++;
    }
}

int main() {
    int t;
    cin >> t;

    // Prepare enough primes for all cases
    generate_primes(MAXN);

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }

        sort(v.begin(), v.end());

        long long a = 0;
        for (int i = 0; i < n; ++i) {
            a += prime[i];
        }

        int count = 0;
        if (a <= sum) {
            cout << 0 << endl;
        } else {
            for (int i = 0; i < n - 1; ++i) {
                sum -= v[i];
                a -= prime[n - 1 - i];
                count++;
                if (sum >= a) break;
            }
            cout << count << endl;
        }
    }

    return 0;
}
