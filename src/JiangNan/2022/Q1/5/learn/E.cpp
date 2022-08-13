#include <iostream>

typedef long long i64;

const int inf = 1e9;
int a[4][4];
int ans = inf;

void flip(int x, int y) {
    a[x][y] = !a[x][y];
    if(x - 1 >= 0) a[x - 1][y] = !a[x - 1][y];
    if(x + 1 <= 3) a[x + 1][y] = !a[x + 1][y];
    if(y - 1 >= 0) a[x][y - 1] = !a[x][y - 1];
    if(y + 1 <= 3) a[x][y + 1] = !a[x][y + 1];
}

void dfs(int p, int step) {
    int jugde = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            jugde += a[i][j];
        }
    }
    if(jugde == 0 || jugde == 16) {
        ans = std::min(ans, step);
    }

    if(p >= 16) {
        return;
    }

    int x = p / 4;
    int y = p % 4;
    dfs(p + 1, step);

    flip(x, y);
    dfs(p + 1, step + 1);
    flip(x, y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            char c;
            std::cin >> c;
            if(c == 'w') {
                a[i][j] = 0;
            } else {
                a[i][j] = 1;
            }
        }
    }
    dfs(0, 0);
    if(ans == inf) {
        std::cout << "Impossible\n";
    } else {
        std::cout << ans << '\n';
    }

    return 0;
}