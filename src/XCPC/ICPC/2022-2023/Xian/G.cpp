/**
 * @author: XiaFan
 * @date: 2023-10-19 12:27
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5E5 + 2;
int tree[N][26], have[N], sum[N];
int cnt = 1;
void insert(std::string s) {
    int p = 1;
    for (auto c : s) {
        int x = c - 'a';
        if (!tree[p][x]) {
            tree[p][x] = ++cnt;
        }
        p = tree[p][x];
        sum[p]++;
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);

    std::vector<std::vector<int>> len(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i].length() <= n) {
            len[a[i].length()].push_back(i);
        }
    }

    int ans = 0;
    for (int l = 1; l <= n; l++) {
        if (l == 1) {
            for (auto id : len[l]) {
                insert(a[id]);
                ans = std::max(ans, l);
            }
            continue;
        }

        for (auto id : len[l]) {
            std::string s1 = a[id].substr(0, l - 1);
            std::string s2 = a[id].substr(1, l - 1);
            if (find(s1) && find(s2)) {
                insert(a[id]);
                ans = std::max(ans, l);
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}