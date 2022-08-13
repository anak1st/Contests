/**
 * @author: XiaFan
 * @date: 05-03 15:04
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;

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
    // gcd(a ^ n - b ^ n, a ^ m - b ^ m) = a ^ gcd(n, m) - b ^ gcd(n, m)；
    // b = 1, gcd(a ^ n - 1, a ^ m - 1) = a ^ gcd(n, m) - 1；
    int t;
    cin >> t;
    while (t--) {
        int a, n, m, k;
        cin >> a >> n >> m >> k;
        // int _s = __gcd(int(pow(a, n) - 1), int(pow(a, m) - 1)) % k;

        int s = (mpower(a, __gcd(n, m), k) - 1) % k;
        cout << s << "\n";
    }

    return 0;
}