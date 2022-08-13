#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

i64 A(int m, int n) {
    i64 res = 1;
    for(int i = 0; i < m; i++) {
        res *= (n - i);
    }
    return res;
}

i64 C(int m, int n) {
    if(m == 0 || m == n) {
        return 1;
    }
    return A(m, n) / A(m, m);
}

int n, sum;
bool finsh = false;
int vis[16];
int ans[16];
void dfs(int step, int cur) {
    if(finsh) {
        return;
    }
    if(step == n) {
        if(cur == sum) {
            for(int i = 1; i <= n; i++) {
                ans[vis[i]] = i;
            }
            finsh = true;
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] >= 0) continue;
        vis[i] = step;
        dfs(step + 1, cur + C(step, n - 1) * i);
        vis[i] = -1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> sum;
    for(int i = 1; i <= n; i++) {
        vis[i] = -1;
        ans[i] = -1;
    }
    dfs(0, 0);
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << ' ';
    }

    return 0;
}