#pragma once
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MAX_SIZE = 1e5 + 10;
int na[MAX_SIZE], nb[MAX_SIZE], nc[MAX_SIZE];

void input_intger(const std::string s, int *p) {
    int l = s.size();
    for (int i = 0; i < l; i++) p[l - 1 - i] = s[i] - '0';
}

std::string output_intger(int *p, int l) {
    std::string ans;
    for (int i = l - 1; i >= 0; i--) ans += p[i] + '0';
    return ans;
}

void remove_leading_zero(int *p, int &l) {
    while (l > 1 && p[l - 1] == 0) l--;
}

std::string add(const std::string &a, const std::string &b) {
    int la = a.size(), lb = b.size();
    int lc = std::max(la, lb);
    int max_lc = lc + 1;
    std::fill(nc, nc + max_lc, 0);
    input_intger(a, na);
    input_intger(b, nb);
    for (int i = 0; i < lc; i++) {
        if (i < la) nc[i] += na[i];
        if (i < lb) nc[i] += nb[i];
        nc[i + 1] += nc[i] / 10;
        nc[i] %= 10;
    }
    if (nc[lc]) lc++;
    return output_intger(nc, lc);
}

std::string sub(const std::string &a, const std::string &b) {
    // assume a >= b
    int la = a.size(), lb = b.size();
    int lc = la;
    std::fill(nc, nc + lc, 0);
    input_intger(a, na);
    input_intger(b, nb);
    for (int i = 0; i < lc; i++) {
        nc[i] = na[i] - nb[i];
        if (nc[i] < 0) na[i] += 10, na[i + 1]--;
    }
    remove_leading_zero(nc, lc);
    return output_intger(nc, lc);
}

std::string mul(const std::string &a, const std::string &b) {
    input_intger(a, na);
    input_intger(b, nb);
    int la = a.size(), lb = b.size();
    int lc = la + lb;
    std::fill(nc, nc + lc, 0);
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < lb; j++) {
            nc[i + j] += na[i] * nb[j];
        }
    }
    for (int i = 0; i < lc; i++) {
        nc[i + 1] += nc[i] / 10;
        nc[i] %= 10;
    }
    remove_leading_zero(nc, lc);
    return output_intger(nc, lc);
}

int mod(const std::string &a, int b) {
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        d = (d * 10 + (a[i] - '0')) % b;
    }
    return d;
}

int sub(int *a, int *b, int La, int Lb) {
    if (La < Lb) return -1;  // 如果a小于b，则返回-1
    if (La == Lb) {
        for (int i = La - 1; i >= 0; i--)
            if (a[i] > b[i])
                break;
            else if (a[i] < b[i])
                return -1;  // 如果a小于b，则返回-1
    }
    for (int i = 0; i < La; i++)  // 高精度减法
    {
        a[i] -= b[i];
        if (a[i] < 0) a[i] += 10, a[i + 1]--;
    }
    for (int i = La - 1; i >= 0; i--)
        if (a[i]) return i + 1;  // 返回差的位数
    return 0;                    // 返回差的位数
}

// n1,n2是字符串表示的被除数，除数,nn是选择返回商还是余数
std::string div(std::string n1, std::string n2, int nn) {
    const int L = 1e5;
    std::string s, v;  // s存商,v存余数
    int a[L], b[L], r[L], La = n1.size(), Lb = n2.size(), i, tp = La;
    // a，b是整形数组表示被除数，除数，tp保存被除数的长度
    std::fill(a, a + L, 0);
    std::fill(b, b + L, 0);
    std::fill(r, r + L, 0);  // 数组元素都置为0
    for (i = La - 1; i >= 0; i--) a[La - 1 - i] = n1[i] - '0';
    for (i = Lb - 1; i >= 0; i--) b[Lb - 1 - i] = n2[i] - '0';
    if (La < Lb || (La == Lb && n1 < n2)) {
        // cout<<0<<endl;
        return n1;
    }                                  // 如果a<b,则商为0，余数为被除数
    int t = La - Lb;                   // 除被数和除数的位数之差
    for (int i = La - 1; i >= 0; i--)  // 将除数扩大10^t倍
        if (i >= t)
            b[i] = b[i - t];
        else
            b[i] = 0;
    Lb = La;
    for (int j = 0; j <= t; j++) {
        int temp;
        while ((temp = sub(a, b + j, La, Lb - j)) >= 0)  // 如果被除数比除数大继续减
        {
            La = temp;
            r[t - j]++;
        }
    }
    for (i = 0; i < L - 10; i++) r[i + 1] += r[i] / 10, r[i] %= 10;  // 统一处理进位
    while (!r[i]) i--;  // 将整形数组表示的商转化成字符串表示的
    while (i >= 0) s += r[i--] + '0';
    // cout<<s<<endl;
    i = tp;
    while (!a[i]) i--;  // 将整形数组表示的余数转化成字符串表示的</span>
    while (i >= 0) v += a[i--] + '0';
    if (v.empty()) v = "0";
    // cout<<v<<endl;
    if (nn == 1) return s;  // 返回商
    if (nn == 2) return v;  // 返回余数

    return s;
}