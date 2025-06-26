#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    cin >> t;
    for (long long int i = 0; i < t; i++) {
        long long k, l1, r1, l2, r2,x=0,y=1;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        long long div = 1;  // Use long long to avoid overflow
        long long  sum = 0;

        // Special case when k == 1 to avoid infinite loop
        if (k == 1) {
            sum += max((min(r2, r1) - max(l1, l2)) + 1, x);
            cout << sum << endl;
            continue;
        }

        // Avoid overflow and infinite loop
        while (div <= r2) {
            sum += max((min(r2 , r1*div) - max(l1*div, l2 )) + y ,x);

            // Prevent overflow before multiplying
            if (div > LLONG_MAX / k) break;

            div *= k;
        }
        cout << sum << endl;
    }
}
