/**
 * @author: XiaFan
 * @date: 05-02 22:47
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

i64 perm(i64 x) {
    return x * (x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    while(true) {
        i64 n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }
        if(n < m) {
            swap(n, m);
        }
        i64 a = (n - m + 1) * perm(m);
        for(i64 i = 1; i < m; i++) {
            a += 2 * perm(i);
        }
        a *= 2;
        i64 b = n * perm(m);
        i64 c = m * perm(n);
        i64 ans = a + b + c;
        cout << ans << "\n";
    }

    return 0;
}