#pragma once
#include <bits/stdc++.h>

using i64 = long long;

const int maxn = 300000 + 5;

namespace pam {

int sz, tot, last;
int cnt[maxn], ch[maxn][26], len[maxn], fail[maxn];
char s[maxn];

int node(int l) {  // 建立一个新节点，长度为 l
    sz++;
    std::fill(ch[sz], ch[sz] + 26, 0);
    len[sz] = l;
    fail[sz] = cnt[sz] = 0;
    return sz;
}

void clear() {  // 初始化
    sz = -1;
    last = 0;
    s[tot = 0] = '$';
    node(0);
    node(-1);
    fail[0] = 1;
}

int getfail(int x) {  // 找后缀回文
    while (s[tot - len[x] - 1] != s[tot]) x = fail[x];
    return x;
}

void insert(char c) {  // 建树
    s[++tot] = c;
    int now = getfail(last);
    if (!ch[now][c - 'a']) {
        int x = node(len[now] + 2);
        fail[x] = ch[getfail(fail[now])][c - 'a'];
        ch[now][c - 'a'] = x;
    }
    last = ch[now][c - 'a'];
    cnt[last]++;
}

i64 solve() {
    i64 ans = 0;
    for (int i = sz; i >= 0; i--) {
        cnt[fail[i]] += cnt[i];
    }
    for (int i = 1; i <= sz; i++) {  // 更新答案
        ans = std::max(ans, 1ll * len[i] * cnt[i]);
    }
    return ans;
}
}  // namespace pam


void example() {
    std::string s;
    std::cin >> s;
    for (auto c : s) {
        pam::insert(c);
    }
    std::cout << pam::solve() << "\n";
}