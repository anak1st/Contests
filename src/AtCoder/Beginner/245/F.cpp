#include <bits/stdc++.h>

typedef long long i64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> f(n + 1);
    std::vector<int> a(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        f[v].push_back(u);
        a[u]++;
    }

    std::queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            q.push(i);
        }
    }

    int ans = n;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        ans--;
        for(auto r : f[p]) {
            a[r]--;
            if(a[r] == 0) {
                q.push(r);
            }
        }
    }
    std::cout << ans << '\n';

    return 0;
}