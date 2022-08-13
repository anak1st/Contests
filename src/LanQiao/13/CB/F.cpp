/**
 * @author: XiaFan
 * @date: 2022-04-11 21:50:26
 * @brief: contest
 **/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int a[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    i64 k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(j > 0) {
                a[i][j] += a[i][j - 1];
            }
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] += a[i - 1][j];
        }
    }

    int ans = 0;
    for(int x1 = 0; x1 < n; x1++) {
        for(int y1 = 0; y1 < m; y1++) {
            for(int x2 = x1; x2 < n; x2++) {
                for(int y2 = y1; y2 < m; y2++) {
                    i64 num = a[x2][y2];
                    if(x1 > 0) {
                        num -= a[x1 - 1][y2];
                    }
                    if(y1 > 0) {
                        num -= a[x2][y1 - 1];
                    }
                    if(x1 > 0 && y1 > 0) {
                        num += a[x1 - 1][y1 - 1];
                    }
                    if(num <= k) {
                        ans++;
                    } else {
                        continue;
                    }
                }
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}