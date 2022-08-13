#include <iostream>
#include <vector>

struct Hungarian {
    int n, m, t;
    std::vector<std::vector<int>> e;
    std::vector<int> vis;
    std::vector<int> mch;
    int ans;

    Hungarian(int _n, int _m, int _t) : e(_n + 1), vis(_n + 1), mch(_m + 1) {
        n = _n;
        m = _m;
        t = _t;
        ans = 0;
    }

    void init() {
        for(int i = 1; i <= t; i++) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
        }
    }

    void run() {
        for(int i = 1; i <= n; i++) {
            if(dfs(i, i)) {
                ans++;
            }
        }
    }

    void pans() {
        std::cout << ans << '\n';
    }

    bool dfs(int u, int tag) {
        if(vis[u] == tag) {
            return false;
        }
        vis[u] = tag;
        for(auto v : e[u]) {
            if((mch[v] == 0) || dfs(mch[v], tag)) {
                mch[v] = u;
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, t;
    std::cin >> n >> m >> t;
    Hungarian h(n, m, t);
    h.init();
    h.run();
    h.pans();

    return 0;
}
