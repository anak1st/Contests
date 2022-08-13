/**
 * @author: XiaFan
 * @date: 06-18 20:30
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> h(3), w(3);
    for(int i = 0; i < 3; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < 3; i++) {
        cin >> w[i];
    }

    int ans = 0;
    vector<int> a(9);
    function<void(int)> dfs = [&](int step) -> void {
        if(step == 3) {
            int sum = a[0] + a[1] + a[2];
            if(h[0] != sum) {
                return;
            }
        }
        if(step == 6) {
            int sum = a[3] + a[4] + a[5];
            if(h[1] != sum) {
                return;
            }
        }
        if(step == 7) {
            int sum = a[0] + a[3] + a[6];
            if(w[0] != sum) {
                return;
            }
        }
        if(step == 8) {
            int sum = a[1] + a[4] + a[7];
            if(w[1] != sum) {
                return;
            }
        }
        if(step == 9) {
            int sum = a[6] + a[7] + a[8];
            if(h[2] != sum) {
                return;
            }
            sum = a[2] + a[5] + a[8];
            if(w[2] != sum) {
                return;
            }
            ans++;
            return;
        }
        for(int i = 1; i <= 28; i++) {
            a[step] = i;
            dfs(step + 1);
        }
    };
    dfs(0);

    cout << ans;

    return 0;
}