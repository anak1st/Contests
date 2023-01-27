#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    scanf("%d", &n);
    // s：序列元素之和
    // c：序列元素数量
    // t：之前所有自由选择事件中，选了几次事件二
    int s = 1, c = 1, t = 0;
    bool failed = false;
    // 按顺序处理所有事件
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        // 事件一
        if (x == 1) s++, c++;
        // 事件二
        else if (x == -1) {
            // 尝试直接执行
            if (c > 1) c--;
            // 无法直接执行，尝试反悔一次自由选择
            else if (t >= 1) t--, s++, c++;
            // 无法反悔，无解
            else failed = true;
        } else {
            // 自由选择事件，尽可能选择事件二
            if (c > 1) t++, c--;
            else s++, c++;
        }
    }
    if (failed) printf("-1\n");
    else {
        int g = gcd(s, c);
        printf("%d %d\n", s / g, c / g);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
