/**
 * @author: XiaFan
 * @date: 04-24 20:14
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    i64 A, B;
    cin >> n >> k >> A >> B;
    vector<i64> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    function<i64(i64, i64)> dfs = [&](i64 left, i64 right) {
        i64 aleft = lower_bound(a.begin(), a.end(), left) - a.begin();
        i64 aright = upper_bound(a.begin(), a.end(), right) - a.begin();
        i64 num = aright - aleft;
        i64 len = right - left + 1;
        if(num == 0) {
            return A;
        }
        i64 ans = B * num * len;
        i64 mid = (left + right) / 2;
        if(len == 1) {
            return ans;
        }
        return min(ans, dfs(left, mid) + dfs(mid + 1, right));
    };

    cout << dfs(1, pow(2, n));

    return 0;
}