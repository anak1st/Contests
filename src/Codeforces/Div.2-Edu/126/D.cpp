/**
 * @author: XiaFan
 * @date: 04-21 12:10
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<i64> b(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    std::vector<i64> v(n + 1);
    i64 sum = 0, cnt = 0, ans = 0;
    for(int i = n; i >= 1; i--) {
        sum -= cnt;
        b[i] -= sum;
        cnt -= v[i];
        if(b[i] > 0) {
            int el = std::min(i, k);
            // if i<k start at i
            i64 need = ceil(1.0 * b[i] / el);
            sum += need * el;
            cnt += need;
            ans += need;
            if(i - el >= 1) {
                v[i - el] += need;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}