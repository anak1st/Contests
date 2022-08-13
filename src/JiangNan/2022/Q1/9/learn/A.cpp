/**
 * @author: XiaFan
 * @date: 05-02 17:57
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;

i64 euler(i64 n) {
    i64 res = n;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res = res / n * (n - 1);
    }
    return res;
}

i64 mpower(i64 a, i64 x, i64 p) {
    a %= p;
    i64 res = 1;
    while (x) {
        if (x % 2) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    string in;
    for (int i = 1; cin >> in; i++) {
        stringstream s(in);
        i64 p, q;
        s >> p;
        s.ignore();
        s >> q;
        i64 g = __gcd(p, q);
        p /= g;
        q /= g;

        i64 x = 1, y = 0;
        while (q % 2 == 0) {
            q /= 2;
            x++;
        }

        i64 phi = euler(q);
        vector<i64> fac;
        for (i64 i = 1; i <= sqrt(phi); i++) {
            if (phi % i == 0) {
                fac.push_back(i);
                fac.push_back(phi / i);
            }
        }
        sort(fac.begin(), fac.end());

        int n = fac.size();
        for (int i = 0; i < n; i++) {
            if (mpower(2ll, fac[i], q) == 1) {
                y = fac[i];
                break;
            }
        }

        cout << "Case #" << i << ": " << x << "," << y << "\n";
    }

    return 0;
}