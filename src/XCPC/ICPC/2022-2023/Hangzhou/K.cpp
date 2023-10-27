/**
 * @author: XiaFan
 * @date: 2023-10-25 15:41
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1E6 + 100;
int tree[N][26], have[N], sum[N];
int cnt = 1;

i64 map[26][26];
i64 ans = 0;
void insert(std::string s) {
    int p = 1;
    for (auto c : s) {
        int x = c - 'a';
        if (!tree[p][x]) {
            tree[p][x] = ++cnt;
        }

        for (int i = 0; i < 26; i++) {
            if (i != x && tree[p][i]) {
                map[x][i] += sum[tree[p][i]];
            }
        }

        p = tree[p][x];
        sum[p]++;
    }

    for (int i = 0; i < 26; i++) {
        if (tree[p][i]) {
            ans += sum[tree[p][i]];
        }
    }

    have[p] = 1;
}
bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        if (!tree[p][x]) {
            return false;
        }
        p = tree[p][x];
    }
    return have[p];
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        insert(s);
    }

    while (q--) {
        std::string t;
        std::cin >> t;

        std::vector<int> pos(26);
        for (int i = 0; i < 26; i++) {
            pos[t[i] - 'a'] = i;
        }

        i64 tmp = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                // std::cerr << map[i][j] << " \n"[j == 25];
                if (pos[i] < pos[j]) {
                    tmp += map[i][j];
                }
            }
        }

        std::cout << ans + tmp << '\n';
    }
    

    return 0;
}