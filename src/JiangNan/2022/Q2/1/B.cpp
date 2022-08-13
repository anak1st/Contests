/**
 * @author: XiaFan
 * @date: 06-22 10:36
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        vector<vector<int>> edge(n, vector<int>(n, inf));
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            edge[a][b] = min(edge[a][b], c);
            edge[b][a] = min(edge[b][a], c);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
                }
            }
        }
        cout << edge[0][n - 1] << "\n";
    }
    return 0;
}