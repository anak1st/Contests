/**
 * @author: XiaFan
 * @date: 2023-02-03 14:11
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    std::string t = "udu";
    int n = s.size();
    int m = 3;
    s = "." + s;
    t = "." + t;

    std::vector pref(n + 2, std::vector<i64>(m + 1, 0));
    std::vector suff(n + 2, std::vector<i64>(m + 1, 0));
    pref[0][0] = 1;
    suff[n + 1][0] = 1;

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                pref[i][j] += pref[i - 1][j - 1];
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        suff[i] = suff[i + 1];
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                suff[i][j] += suff[i + 1][j - 1];
            }
        }
    }

    i64 ans = 0;
    auto chmax = [&](i64 x) -> bool {
        if (ans < x) {
            ans = x;
            return true;
        } else {
            return false;
        }
    };

    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'u') {
            //std::cerr << "u: " << pref[i - 1][2] << " " << suff[i + 1][2] << "\n";
            if (chmax(pref[i - 1][2])) {
                p = i;
            }
            if (chmax(suff[i + 1][2])) {
                p = i;
            }
        } else if (s[i] == 'd') {
            //std::cerr << "d: " << pref[i - 1][1] << " " << suff[i + 1][1] << "\n";
            if (chmax(pref[i - 1][1] * suff[i + 1][1])) {
                p = i;
            }
        }
    }
    s[p] = 'x';
    std::cout << s.substr(1) << std::endl;
    
    return 0;
}