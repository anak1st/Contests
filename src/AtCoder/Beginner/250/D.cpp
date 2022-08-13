/**
 * @author: XiaFan
 * @date: 05-09 22:50
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128_t;

vector<i64> make_primes(i64 psize) {
    vector<bool> pre(psize, true);
    for (i64 i = 2; i < psize; i++) {
        if (!pre[i]) {
            continue;
        }
        for (i64 j = 2; i * j < psize; j++) {
            pre[i * j] = false;
        }
    }

    vector<i64> a;
    for (i64 i = 2; i < psize; i++) {
        if (pre[i]) {
            a.push_back(i);
        }
    }
    return a;
}

std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += ('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    i64 psize = ceil(cbrt(ceil(n / 2))) + 10;
    vector<i64> a = make_primes(psize);

    i64 ans = 0;
    for (size_t i = 1; i < a.size(); i++) {
        i64 q = a[i];
        for (size_t j = 0; j < i; j++) {
            i64 p = a[j];
            i128 k = p * q * q * q;

            if (k > n) {
                break;
            }
            ans++;
        }
    }
    cout << ans;

    return 0;
}