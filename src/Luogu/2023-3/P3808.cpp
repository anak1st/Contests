/**
 * @author: XiaFan
 * @date: 2023-03-03 20:32
 **/
#include <bits/stdc++.h>
using i64 = long long;

// Aho-Corasick Automaton
constexpr int N = 5e5;
int tree[N][26];
int fail[N], have[N];
int cnt = 0;
void insert(std::string t) {
    int p = 0;
    for (auto c : t) {
        int x = c - 'a';
        if (!tree[p][x]) {
            tree[p][x] = ++cnt;
        }
        p = tree[p][x];
    }
    have[p]++;
}
void build() {
    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (tree[0][i]) {
            fail[tree[0][i]] = 0;
            q.push(tree[0][i]);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (tree[x][i]) {
                fail[tree[x][i]] = tree[fail[x]][i];
                q.push(tree[x][i]);
            } else {
                tree[x][i] = tree[fail[x]][i];
            }
        }
    }
}
int query(const std::string &s) {
    int ans = 0;
    int p = 0;
    for (const auto c : s) {
        p = tree[p][c - 'a'];
        for (int t = p; t && ~have[t]; t = fail[t]) {
            ans += have[t];
            have[t] = -1;
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::string> S(n);
    for (auto &s : S) {
        std::cin >> s;
    }
    std::string T;
    std::cin >> T;
    for (const auto &s : S) {
        insert(s);
    }
    build();
    std::cout << query(T);

    return 0;
}