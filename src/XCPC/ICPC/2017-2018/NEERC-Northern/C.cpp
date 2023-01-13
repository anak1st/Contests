/**
 * @author: XiaFan
 * @date: 2023-01-09 18:48
 **/
#include <bits/stdc++.h>
using i64 = long long;

std::string change(std::string s, std::bitset<26> b) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (b[s[i] - 'a']) {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    freopen("consonant.in", "r", stdin);
    freopen("consonant.out", "w", stdout);

    std::string s;
    std::cin >> s;

    std::vector<bool> skip(26);
    skip['a' - 'a'] = true;
    skip['e' - 'a'] = true;
    skip['i' - 'a'] = true;
    skip['o' - 'a'] = true;
    skip['u' - 'a'] = true;
    skip['w' - 'a'] = true;
    skip['y' - 'a'] = true;

    std::vector cnt(26, std::vector<int>(26));
    for (int i = 0; i < (int)s.size() - 2; i++) {
        cnt[s[i] - 'a'][s[i + 1] - 'a']++;
    }

    int max = 0;
    std::bitset<26> status, ans;

    auto fastcalc = [&]() {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (skip[i]) continue;
            for (int j = 0; j < 26; j++) {
                if (skip[j]) continue;
                if (status[i] ^ status[j]) {
                    res += cnt[i][j];
                }
            }
        }
        return res;
    };

    // int debug = 0;
    std::function<void(int)> dfs = [&](int step) {
        // debug++;
        // if (debug % 1000 == 0) {
        //     std::cerr << debug << "\n";
        // }
        if (step == 26) {
            // std::string t = change(s, status);
            // int tmp = calc(t);
            int tmp = fastcalc();
            if (tmp > max) {
                max = tmp;
                ans = status;
            }
            return;
        }
        dfs(step + 1);
        if (!skip[step]) {
            status[step] = 1;
            dfs(step + 1);
            status[step] = 0;
        }
    };

    dfs(0);
    std::cout << change(s, ans);
    // std::cerr << debug;
    // std::cerr << max;

    return 0;
}