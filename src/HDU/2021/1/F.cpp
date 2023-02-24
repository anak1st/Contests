/**
 * @author: XiaFan
 * @date: 2023-02-17 20:31
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int inf = 1e9;
constexpr int N = 1e6 * 30 + 10;
int tree[N][2], pos[N];
int cnt = -1;
int new_node() {
    cnt++;
    tree[cnt][0] = tree[cnt][1] = 0;
    pos[cnt] = inf;
    return cnt;
}
void init() {
    cnt = -1;
    new_node();
}
void insert(int x, int id) {
    int p = 0;
    auto X = std::bitset<32>(x);
    for (int i = 30; i >= 0; i--) {
        int to = X[i];
        if (!tree[p][to]) {
            tree[p][to] = new_node();
        }
        p = tree[p][to];
        pos[p] = std::min(pos[p], id);
    }
}
int find(int x, int k) {
    int p = 0;
    auto X = std::bitset<32>(x);
    auto K = std::bitset<32>(k);
    int ans = inf;
    for (int i = 30; i >= 0; i--) {
        // if K_i == 0:
        // if X_i^num_i == 1, x > k, 成功
        // if X_i^num_i == 0, x ^ num 仍然有机会 > k, 继续
        int to = X[i];
        if (K[i] == 0) {
            ans = std::min(ans, pos[tree[p][to ^ 1]]);
            p = tree[p][to];
        } else {
            p = tree[p][to ^ 1];
        }
        if (!p) {
            return ans;
        }
    }
    ans = std::min(ans, pos[p]);
    return ans;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    init();
    int xsum = 0, left = -1, right = -1;
    insert(0, n);
    for (int i = n - 1; i >= 0; i--) {
        xsum ^= a[i];
        int ans = find(xsum, k);
        if (ans != inf) {
            if (left == -1 || ans - i <= right - left) {
                left = i;
                right = ans;
            }
        }
        insert(xsum, i);
    }
    if (left == -1) {
        std::cout << -1 << "\n";
    } else {
        std::cout << left + 1 << ' ' << right << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}