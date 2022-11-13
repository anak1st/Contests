/**
 * @author: XiaFan
 * @date: 05-12 19:50
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using choose = bitset<15>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (auto &i : s) {
        cin >> i;
    }

    int ans = 0;
    for (int tmp = 0; tmp < (1 << n); tmp++) {
        choose a(tmp);
        map<char, int> count;
        for (int i = 0; i < n; i++) {
            if (a.test(i)) {
                for (int j : s[i]) {
                    count[j]++;
                }
            }
        }
        int cur = 0;
        for (auto [_, x] : count) {
            if (x == k) {
                cur++;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans;

    return 0;
}