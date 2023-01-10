/**
 * @author: XiaFan
 * @date: 09-23 20:53
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = '?' + s;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            //std::cout << "000 " << i << "\n";
            ans += i;
            s[i] = '2';
        }

        if (s[i] == '2') {
            for (int j = 2 * i; j <= n; j += i) {
                if (s[j] == '1') {
                    break;
                } else if (s[j] == '0') {
                    ans += i;
                    s[j] = '2';
                    //std::cout << "111 " << j << " " << i << "\n";
                }
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}