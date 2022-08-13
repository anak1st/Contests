/**
 * @author: XiaFan
 * @date: 05-02 09:34
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    i64 n, k;
    cin >> n >> k;
    i64 d = 0;
    i64 fast = n * 2 / k / (k + 1);
    for(i64 i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(i <= fast) {
                d = max(d, i);
            }
            if(n / i <= fast) {
                d = max(d, n / i);
            }
        }
    }
    if(d == 0) {
        cout << "-1";
        return 0;
    }
    for(i64 i = 1; i <= k - 1; i++) {
        cout << d * i << " ";
        n -= d * i;
    }
    cout << n;

    return 0;
}