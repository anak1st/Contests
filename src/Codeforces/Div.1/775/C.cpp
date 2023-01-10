#include <bits/stdc++.h>
using i64 = long long;

struct ac {
    std::vector<int> pi, pj;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<int, ac> c;
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x;
            std::cin >> x;
            c[x].pi.push_back(i);
            c[x].pj.push_back(j);
        }
    }

    i64 ans = 0;
    for(auto tmp : c) {
        for(auto t : {tmp.second.pi, tmp.second.pj}) {
            std::sort(t.begin(), t.end());
            i64 last = t.size() - 1;
            i64 tans = 0;
            for(int i = 1; i <= last; i++) {
                i64 d = t[i] - t[i - 1];
                tans += (i64)(last + 1 - i) * (i64)i * d;
            }
            ans += tans;
        }
    }
    std::cout << ans << '\n';

    return 0;
}