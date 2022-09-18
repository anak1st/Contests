/**
 * @author: XiaFan
 * @date: 09-11 22:24
 **/
#include <bits/stdc++.h>
using i64 = long long;

namespace Trie {

constexpr int n = 5e5, m = 26;
int cnt = 1;
int trie[n][m];
int fail[n], have[n];

void init() {
    std::fill(trie[0], trie[0] + m, 1);
}

void insert(std::string t) {
    int p = 1;
    for (auto c : t) {
        int x = c - 'a';
        if (!trie[p][x]) {
            trie[p][x] = ++cnt;
        }
        p = trie[p][x];
    }
    have[p] = 1;
}

void build() {
    std::queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        have[x] |= have[fail[x]];
        for (int i = 0; i < m; i++) {
            if (trie[x][i]) {
                fail[trie[x][i]] = trie[fail[x]][i];
                q.push(trie[x][i]);
            } else {
                trie[x][i] = trie[fail[x]][i];
            }
        }
    }
}

bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        p = trie[p][x];
        if (have[p]) {
            return true;
        }
    }
    return false;
}

}  // namespace Trie

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    std::vector<std::string> t(n);

    Trie::init();

    for (auto t_i : t) {
        std::cin >> t_i;
        Trie::insert(t_i);
    }

    Trie::build();

    int ans = 0;
    int p = 1;
    for (int i = 0; i < int(s.length()); i++) {
        int x = s[i] - 'a';
        p = Trie::trie[p][x];
        if (Trie::have[p]) {
            ans++;
            p = 1;
        }
    }
    std::cout << ans << "\n";

    return 0;
}