/**
 * @author: XiaFan
 * @date: 11-17 22:42
 **/
#include <bits/stdc++.h>

using i64 = long long;

const int N = 3e5 + 1;

struct Query {
    int l, r, id;

    friend bool operator<(const Query& lhs, const Query& rhs) {
        if (bl[lhs.l] != bl[rhs.l]) {
            return lhs.l < rhs.l;
        }if (bl[lhs.l] % 2 == 1) {
            return lhs.r < rhs.r;
        } else {
            return lhs.r > rhs.r;
        }
    }
};

int n, m, a[N], cnt[N], bl[N], ans[N], maxn, sum[N];
Query q[N];

void add(int x) {
    cnt[a[x]]++;
    sum[cnt[a[x]]]++;
    if (cnt[a[x]] > maxn) {
        maxn = cnt[a[x]];
    }
    return;
}
void del(int x) {
    if (sum[cnt[a[x]]] == 1 && maxn == cnt[a[x]]) {
        maxn--;
    }
    sum[cnt[a[x]]]--;
    cnt[a[x]]--;
    return;
}

int main() {
    std::cin >> n >> m;
    int len = sqrt(n);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        bl[i] = (i - 1) / len + 1;
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    std::sort(q + 1, q + m + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        while (r > q[i].r) del(r--);
        while (l < q[i].l) del(l++);
        ans[q[i].id] = 1;
        int L = q[i].r - q[i].l + 1;
        int left = L - maxn;
        if (maxn > left) {
            ans[q[i].id] += maxn - left - 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        std::cout << ans[i] << "\n";
    }
    return 0;
}