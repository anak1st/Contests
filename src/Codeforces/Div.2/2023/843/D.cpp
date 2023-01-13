/**
 * @author: XiaFan
 * @date: 2023-01-12 22:06
 **/
#include <bits/stdc++.h>
using i64 = long long;

const int N = 3e5;
std::vector<int> primes;
int minp[N + 1]; // minp[i] = min prime factor of i
void init() {
    for (int i = 2; i <= N; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) break;
            minp[i * p] = p;
            if (i % p == 0) break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    if (s == t) {
        std::cout << 1 << "\n" << s + 1;
        return 0;
    }

    std::vector<std::vector<int>> fact(n);
    std::vector<std::set<int>> div(N);
    for (int i = 0; i < n; i++) {
        int t = a[i];
        while (t > 1) {
            if (fact[i].empty() || fact[i].back() != minp[t]) {
                fact[i].push_back(minp[t]);
            }
            div[minp[t]].insert(i);
            t /= minp[t];
        }
    }

    std::vector<int> pre(n);
    pre[s] = s;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) {
            std::vector<int> ans{t};
            int i = t;
            while (i != s) {
                ans.push_back(pre[i]);
                i = pre[i];
            }
            std::reverse(ans.begin(), ans.end());
            std::cout << ans.size() << "\n";
            for (auto v : ans) {
                std::cout << v + 1 << " ";
            }
            return 0;
        }
        for (auto f : fact[u]) {
            while (!div[f].empty()) {
                int v = *div[f].begin();
                pre[v] = u;
                q.push(v);
                for (auto r : fact[v]) {
                    div[r].erase(v);
                }
            }
        }
    }

    std::cout << -1;
    return 0;
}