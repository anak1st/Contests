/**
 * @author: XiaFan
 * @date: 05-02 19:59
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  // 0 -> nullptr

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int g = a[0];
    for(int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }
    if(g > 1) {
        cout << "YES\n";
        cout << "0\n";
        return 0;
    }
    int ans = 0;
    int j = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 && j == -1) {
            j = i;
        }
        if(a[i] % 2 == 0) {
            if(j != -1) {
                int len = i - j;
                ans += len % 2 * 2 + len / 2;
            }
            j = -1;
        }
    }
    if(j != -1) {
        int len = n - j;
        ans += len % 2 * 2 + len / 2;
    }
    cout << "YES\n";
    cout << ans << "\n";
    return 0;
}