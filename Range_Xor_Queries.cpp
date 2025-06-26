#include <bits/stdc++.h>
using namespace std;

#define int long long  // Correct macro

int power(int n) {
    for (int i = 0; i < 62; i++) {
        if (n <= (1LL << i)) return (1LL << i);
    }
    return -1;
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    int a = power(n);

    vector<int> v(2 * a, 0);
    for (int i = a; i < a + n; i++) {
        cin >> v[i];
    }

    for (int i = a - 1; i >= 1; i--) {
        v[i] = v[2 * i] ^ v[2 * i + 1];
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x += (a - 1);
        y += (a - 1);
        int val = 0;
        while (x <= y) {
            if (x % 2 == 1) val ^= v[x++];
            if (y % 2 == 0) val ^= v[y--];
            x /= 2;
            y /= 2;
        }
        cout << val << endl;
    }
}
