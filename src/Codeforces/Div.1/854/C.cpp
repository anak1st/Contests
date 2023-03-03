/**
 * @author: XiaFan
 * @date: 2023-02-27 23:17
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    std::vector<int> ch(26);
    for (auto c : s) {
        ch[c - 'a']++;
    }

    std::string a;
    for (int i = 0; i < 26; i++) {
        if (ch[i] > 0) {
            a += std::string(ch[i] / 2, 'a' + i);
            ch[i] %= 2;
        }
        if (ch[i] % 2) {
            break;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (ch[i] > 0) {
            cnt++;
        }
    }

    std::string b;
    if (cnt == 1) {
        int x = -1;
        for (int i = 0; i < 26; i++) {
            if (ch[i]) {
                x = i;
                break;
            }
        }
        b = std::string(ch[x], 'a' + x);
    } else if (cnt == 2) {
        int x = -1, y = -1;
        for (int i = 0; i < 26; i++) {
            if (ch[i]) {
                if (x == -1) {
                    x = i;
                } else {
                    y = i;
                }
            }
        }
        b = std::string(ch[x], 'a' + x);
        b = std::string(ch[y] / 2, 'a' + y) + b;
        ch[y] -= ch[y] / 2;
        b = b + std::string(ch[y], 'a' + y);
    } else if (cnt > 2) {
        int x = -1;
        for (int i = 0; i < 26; i++) {
            if (ch[i]) {
                if (x == -1) {
                    x = i;
                } else {
                    b += std::string(ch[i], 'a' + i);
                }
            }
        }
        b += std::string(ch[x], 'a' + x);
    }

    std::string ans = a + b;
    std::reverse(a.begin(), a.end());
    ans += a;
    auto tmp = ans;
    std::reverse(ans.begin(), ans.end());
    ans = std::max(ans, tmp);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}