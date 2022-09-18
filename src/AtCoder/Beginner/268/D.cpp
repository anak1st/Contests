/**
 * @author: XiaFan
 * @date: 09-12 19:29
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        len += s[i].length();
    }

    std::set<std::string> t;
    for (int i = 0; i < m; i++) {
        std::string tmp;
        std::cin >> tmp;
        t.insert(tmp);
    }

    std::string ans = "-1";
    std::vector<bool> vis(n);
    std::function<void(int, int, std::string)> 
    dfs = [&](int x, int space, std::string str) {
        if (ans != "-1") {
            return;
        }

        if (x == n) {
            if (!t.count(str) && int(str.length()) >= 3 && int(str.length()) <= 16) {
                ans = str;
            }
            // std::cout << str << "\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }

            vis[i] = true;
            if (x == 0) {
                dfs(x + 1, space, str + s[i]);
            } else {
               for (int j = 1; j <= space; j++) {
                    dfs(x + 1, space - j, str + std::string(j, '_') + s[i]);
                } 
            }
            
            vis[i] = false;
        }
    };

    dfs(0, 16 - len, "");
    std::cout << ans;
    
    return 0;
}