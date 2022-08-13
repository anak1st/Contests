/**
 * @author: XiaFan
 * @date: 06-23 11:50
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;
const int inf = 1e9;

template <typename T> 
std::vector<T> Dijkstra(int start, const std::vector<std::vector<T> > &G) {
    int n = G.size();
    std::vector<T> d(n, inf);
    d[start] = 0;
    std::vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (k == -1 || d[j] < d[k]) {
                k = j;
            }
        }
        vis[k] = true;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            d[j] = std::min(d[j], d[k] + G[k][j]);
            // d[j] = std::min(d[j], std::max(d[k], G[k][j]));
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;
    x--;
    vector<vector<int> > G(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a][b] = c;
    }
    vector<int> res1 = Dijkstra<int>(x, G);
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(G[i][j], G[j][i]);
        }
    }
    vector<int> res2 = Dijkstra<int>(x, G);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(x != i) {
            ans = max(ans, res1[i] + res2[i]);
        }
    }
    cout << ans;

    return 0;
}