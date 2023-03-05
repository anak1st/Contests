#pragma once
#include "XCPC.h"

struct query {
    int l, r, id;
};
constexpr int N = 1e5 + 10;
query querys[N];
int n, m, BLOCK_SIZE, l, r;
i64 nowAns, ans[N];

// O(n^(1.5))
void move(int pos, int sign) {
    // update nowAns
}

void solve() {
    BLOCK_SIZE = int(ceil(pow(n, 0.5)));
    std::sort(querys, querys + m);
    for (int i = 0; i < m; ++i) {
        const query &q = querys[i];
        while (l > q.l) move(--l, 1);
        while (r < q.r) move(r++, 1);
        while (l < q.l) move(l++, -1);
        while (r > q.r) move(--r, -1);
        ans[q.id] = nowAns;
    }
}