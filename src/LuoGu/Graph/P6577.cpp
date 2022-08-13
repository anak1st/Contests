#include <bits/stdc++.h>

const int MAXN = 510;
const int inf = 1e9;

int n, m;
int e[MAXN][MAXN];

int lx[MAXN], ly[MAXN], py[MAXN], d;
bool vx[MAXN], vy[MAXN];

bool dfs(int u) {
    vx[u] = 1;
    for(int i = 1; i <= n; ++i) {
        if(!vy[i]) {
            if(lx[u] + ly[i] == e[u][i]) {
                vy[i] = 1;
                if(!py[i] || dfs(py[i])) {
                    py[i] = u;
                    vy[i] = 1;
                    return 1;
                }
            } else {
                d = std::min(d, lx[u] + ly[i] - e[u][i]);
            }
        }
    }

    return 0;
}

int main() {
    for(int i = 1; i <= n; ++i) {
        while(1) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            d = inf;
            if(dfs(i)) {
                break;
            }
            for(int j = 1; j <= n; ++j) {
                if(vx[j]) lx[j] -= d;
                if(vy[j]) ly[j] += d;
            }
        }
    }

    return 0;
}