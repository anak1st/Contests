/**
 * @author: XiaFan
 * @date: 04-19 23:14
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    std::vector<int> f(n, 0);
    int tmpk = k;
    for(int i = 0; i < n && tmpk > 0; i++) {
        if(k % 2 == s[i] - '0') {
            f[i] = 1;
            tmpk--;
        }
    }
    f[n - 1] += tmpk;

    for(int i = 0; i < n; i++) {
        if((k - f[i]) % 2 == 1) {
            s[i] = '0' + !(s[i] - '0');
        }
    }

    std::cout << s << '\n';
    for(auto x : f) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}