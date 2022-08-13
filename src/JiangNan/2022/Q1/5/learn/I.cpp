#include <algorithm>
#include <iostream>
#include <set>

typedef long long i64;

int a[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
std::set<int> st;

void dfs(int x, int y, int step, int num) {
    if(step == 6) {
        st.insert(num);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) {
            continue;
        }
        dfs(nx, ny, step + 1, (num * 10 + a[nx][ny]));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cin >> a[i][j];
        }
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            dfs(i, j, 1, a[i][j]);
        }
    }

    std::cout << st.size() << '\n';
    /*for(auto it : st) {
        std::cerr << it << '\n';
    }*/
    return 0;
}