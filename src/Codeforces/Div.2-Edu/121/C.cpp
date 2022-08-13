#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 12345;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        int k[maxN];
        i64 h[maxN];
        k[0] = 0;
        for(int i = 1; i <= n; i++) { cin >> k[i]; }
        for(int i = 1; i <= n; i++) { cin >> h[i]; }
        int j = n;
        i64 sum = 0;
        for(int i = n - 1; i >= 1; i--) {
            int time = k[j] - k[i];
            if(h[j] > time) {
                h[j] = max(h[j], h[i] + time);
            } else {
                sum += h[j] * (h[j] + 1) / 2;
                j = i;
            }
        }
        sum += h[j] * (h[j] + 1) / 2;
        cout << sum << '\n';
        if(0) {
            cout << n << '\n';
            for(int i = 1; i <= n; i++) { cout << k[i] << ' '; }
            cout << '\n';
            for(int i = 1; i <= n; i++) { cout << h[i] << ' '; }
            cout << '\n';
        }
    }
    return 0;
}