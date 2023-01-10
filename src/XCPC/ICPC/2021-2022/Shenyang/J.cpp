/**
 * @author: XiaFan
 * @date: 11-14 20:09
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<std::string, int> mp;
    std::queue<std::string> q;
    mp["0000"] = 0;
    q.push("0000");
    while (!q.empty()) {
        std::string s = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < 4; j++) {
                std::string u = s, d = s;
                for (int k = i; k <= j; k++) {
                    u[k] = (u[k] - '0' + 1) % 10 + '0';
                    d[k] = (d[k] - '0' + 9) % 10 + '0';
                }
                if (!mp.count(u)) {
                    mp[u] = mp[s] + 1;
                    q.push(u);
                }
                if (!mp.count(d)) {
                    mp[d] = mp[s] + 1;
                    q.push(d);
                }
            }
        }
    }
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        std::string a, b;
        std::cin >> a >> b;
        std::string c(4, '0');
        for (int i = 0; i < 4; i++) {
            c[i] = (b[i] - a[i] + 10) % 10 + '0';
        }
        std::cout << mp[c] << '\n';
    }
    
    return 0;
}