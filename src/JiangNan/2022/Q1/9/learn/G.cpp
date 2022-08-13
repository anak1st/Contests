/**
 * @author: XiaFan
 * @date: 05-02 19:40
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
    while(x) {
        if(x % 2) {
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

    int t;
    cin >> t;
    while(t--) {
        i64 p, n;
        cin >> p >> n;
        i64 ans = 0;
        for(int i = 0; i < n; i++) {
            i64 a, b;
            cin >> a >> b;
            ans = (ans + mpower(a, b, p)) % p;
        }
        cout << ans << "\n";
    }

    return 0;
}