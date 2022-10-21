<div align='center'><font size='7'>Templates</font></div>

<div align='center'><font size='5'>By Xia Fan</font></div>

- [1. Data Structure](#1-data-structure)
  - [1.1. Disjoint Set Union](#11-disjoint-set-union)
  - [1.2. Fenwick Tree](#12-fenwick-tree)
  - [1.3. Sparse Table](#13-sparse-table)
  - [1.4. Segment Tree](#14-segment-tree)
- [2. Algorithms](#2-algorithms)
  - [2.1. Merge Sort](#21-merge-sort)
- [3. Number](#3-number)
  - [3.1. Mint](#31-mint)
  - [3.2. Permutation and Combination](#32-permutation-and-combination)
- [4. String](#4-string)
  - [4.1. KMP](#41-kmp)
  - [4.2. Trie](#42-trie)
  - [4.3. AC Automaton](#43-ac-automaton)

<div STYLE="page-break-after: always;"></div>

# 1. Data Structure

## 1.1. Disjoint Set Union
``` C++
#include <vector>
#include <numeric>

// Disjoint Set Union
class DSU {
private:
    std::vector<int> f, s;

public:
    DSU(int n) : f(n), s(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        s[x] += s[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return s[find(x)];
    }
};
```

<div STYLE="page-break-after: always;"></div>

## 1.2. Fenwick Tree
``` C++
#include <cassert>
#include <vector>

// FenwickTree
template <typename T> class Fenwick {
private:
    int n;
    std::vector<T> a;

    int lowbit(int x) {
        return x & -x;
    }

    T sum(int pos) {
        if (pos < 0) {
            return 0;
        }
        T val = 0;
        for (int i = pos + 1; i >= 1; i -= lowbit(i)) {
            val += a[i - 1];
        }
        return val;
    }

public:
    Fenwick(int size) 
    : n(size), a(n) 
    {}

    Fenwick(const std::vector<T> &v) 
    : n(int(v.size())), a(n) 
    {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }

    void add(int pos, T val) {
        for (int i = pos + 1; i <= n; i += lowbit(i)) {
            a[i - 1] += val;
        }
    }

    T sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};
```

<div STYLE="page-break-after: always;"></div>

## 1.3. Sparse Table
``` C++
#include <cassert>
#include <cmath>
#include <functional>
#include <vector>

// Sparse Table
template <typename T, class F = std::function<T(const T&, const T&)>> 
class ST {
private:
    int n;
    std::vector<std::vector<T>> mat;
    F func;

public:
    ST(const std::vector<T>& a, const F& f) : n(int(a.size())), func(f) {
        assert(n > 0);
        // int max_log = 32 - __builtin_clz(n);
        int max_log = int(log2(n)) + 1;
        mat.resize(max_log);
        mat[0] = a;
        for (int i = 1; i < max_log; i++) {
            int m = n - (1 << i) + 1;
            mat[i].resize(m);
            for (int j = 0; j < m; j++) {
                mat[i][j] = func(mat[i - 1][j], mat[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to < n);
        // int lg = 32 - __builtin_clz(to - from + 1) - 1;
        int lg = int(log2(to - from + 1));
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

```

<div STYLE="page-break-after: always;"></div>

## 1.4. Segment Tree
``` C++
#include <cassert>
#include <iostream>
#include <vector>

// Segment Tree
template <typename T> class SegTree {
private:
    struct node {
        int l, r;
        T sum;
        T tag;
        T max, min;
        int cnt;
        
        node() : sum(0), tag(0), max(0), min(0), cnt(0) {}
        
        int mid() {
            return (l + r) / 2;
        }
    };

    int n;
    std::vector<node> tree;

    int ls(int root) {
        return root * 2 + 1;
    }
    
    int rs(int root) {
        return root * 2 + 2;
    }

    void push_up(int root) {
        tree[root].sum = tree[ls(root)].sum + tree[rs(root)].sum;
        tree[root].max = std::max(tree[ls(root)].max, tree[rs(root)].max);
        // tree[root].cnt = tree[m_l(root)].cnt + tree[m_r(root)].cnt;
    }

    void build(int root, const std::vector<T> &num) {
        if (tree[root].l == tree[root].r) {
            tree[root].sum = num[tree[root].l];
            tree[root].max = num[tree[root].l];
            // tree[root].cnt = 1;
            return;
        }
        int mid = tree[root].mid();
        tree[ls(root)].l = tree[root].l;
        tree[ls(root)].r = mid;
        tree[rs(root)].l = mid + 1;
        tree[rs(root)].r = tree[root].r;

        build(ls(root), num);
        build(rs(root), num);
        push_up(root);
    }

    void change(int root, T val) {
        tree[root].tag += val;
        tree[root].sum += (val * (tree[root].r - tree[root].l + 1));
        // tree[root].sum = val;
        // tree[root].sum += (val * tree[root].cnt);
    }

    void push_down(int root) {
        change(ls(root), tree[root].tag);
        change(rs(root), tree[root].tag);
        tree[root].tag = 0;
    }

    void update(int root, int left, int right, int val) {
        // assert(root < 4 * n);
        if (left <= tree[root].l && tree[root].r <= right) {
            change(root, val);
            return;
        }
        push_down(root);
        int mid = tree[root].mid();
        if (left <= mid)      update(ls(root), left, right, val);
        if (mid + 1 <= right) update(rs(root), left, right, val);
        push_up(root);
    }
    
    void cnt_update(int root, int pos, int val) {
        // assert(root < 4 * n);
        tree[root].cnt += val;
        if (tree[root].l == tree[root].r) {
            return;
        }
        push_down(root);
        int mid = tree[root].mid();
        if (pos <= mid) {
            cnt_update(ls(root), pos, val);
        } else {
            cnt_update(rs(root), pos, val);
        }
        push_up(root);
    }
    
    T query(int root, int left, int right) {
        // assert(root < 4 * n);
        if (left <= tree[root].l && tree[root].r <= right) {
            return tree[root].sum;
        }
        T ans = 0;
        push_down(root);
        int mid = tree[root].mid();
        if (left <= mid) {
            ans += query(ls(root), left, right);
            // ans = max(ans, query(ls(root), left, right));
        }
        if (mid + 1 <= right) {
            ans += query(rs(root), left, right);
            // ans = max(ans, query(rs(root), left, right));
        }
        return ans;
    }

public:
    SegTree(const std::vector<T> &num) : n(num.size()), tree(num.size() * 4) {
        tree[0].l = 0;
        tree[0].r = n - 1;
        build(0, num);
    }

    void update(int left, int right, int val) {
        update(0, left, right, val);
    }

    T query(int left, int right) {
        return query(0, left, right);
    }
    
    void cnt_update(int pos, int val) {
        assert(val == -1 || val == 1);
        push_down(0);
        cnt_update(0, pos, val);
    }
};
```

<div STYLE="page-break-after: always;"></div>

# 2. Algorithms

## 2.1. Merge Sort

``` C++
#include <vector>

namespace __MS {

template <typename T> 
i64 Merge(int left, int right, std::vector<T> &a, std::vector<T> &b) {
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;
    i64 res = 0;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            res += (j - k);
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= right) {
        b[k++] = a[j++];
    }
    for (int i = left; i <= right; i++) {
        a[i] = b[i];
    }
    return res;
}

template <typename T> 
i64 Sort(int left, int right, std::vector<T> &a, std::vector<T> &b) {
    i64 res = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        res += Sort<T>(left, mid, a, b);
        res += Sort<T>(mid + 1, right, a, b);
        res += Merge<T>(left, right, a, b);
    }
    return res;
}
}  // namespace __MS

template <typename T> i64 MergeSort(std::vector<T> &a) {
    std::vector<T> b(a);
    return __MS::Sort<T>(0, a.size() - 1, a, b);
}
```

<div STYLE="page-break-after: always;"></div>

# 3. Number

## 3.1. Mint 
``` C++
#include <cassert>
#include <iostream>

constexpr int P = 998244353;

int modulo(i64 x) {
    return (x % P + P) % P;
}

template <class T> T fpow(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Mint {
private:
    int x;

public:
    Mint() : x(0) {}
    Mint(int x_) : x(modulo(x_)) {}
    Mint(i64 x_) : x(modulo(x_)) {}

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 temp;
        is >> temp;
        a.x = modulo(temp);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        os << a.x;
        return os;
    }

    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(modulo(-x));
    }

    Mint inv() const {
        assert(x != 0);
        return fpow(*this, P - 2);
    }

    Mint &operator*=(const Mint &rhs) {
        x = modulo(1LL * x * rhs.x);
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = modulo(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = modulo(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        return *this *= rhs.inv();
    }

    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
};
```

<div STYLE="page-break-after: always;"></div>

## 3.2. Permutation and Combination
``` C++
template <typename T> T A(int n, int m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans *= a;
    }
    return ans;
}

template <typename T> T C(int n, int m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans = ans * a / i;
    }
    return ans;
}
```

<div STYLE="page-break-after: always;"></div>

# 4. String 

## 4.1. KMP 
``` C++
#include <string>
#include <vector>

// Knuth-Morris-Pratt
std::vector<int> get_next(std::string &s) {
    int n = s.size();
    std::vector<int> next(n + 1, 0);
    next[0] = -1;
    for (int i = 0, j = -1; i < n;) {
        if (j == -1 || s[i] == s[j]) {
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;  // size (n+1)
}

void KMP() {
    std::string a, b;
    std::cin >> a >> b;
    int na = a.length();
    int nb = b.length();
    auto next = get_next(a);
    for (int i = 0, j = 0; j < nb; j++) {
        while (i > 0 && b[j] != a[i]) {
            i = next[i];
        }
        if (b[j] == a[i]) {
            i++;
        }
        if (i == na) {
            // success !!!
            i = next[i];
        }
    }
    return;
}
```

<div STYLE="page-break-after: always;"></div>

## 4.2. Trie
``` C++
#include <string>

namespace Trie {
constexpr int N = 5E5 + 2;

int trie[N][26], have[N], sum[N];
int cnt = 1;

void insert(std::string s) {
    int p = 1;
    for (auto c : s) {
        int x = c - 'a';
        if (!trie[p][x]) {
            trie[p][x] = ++cnt;
        }
        p = trie[p][x];
        sum[p]++;
    }
    have[p] = 1;
}

bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        if (!trie[p][x]) {
            return false;
        }
        p = trie[p][x];
    }
    return have[p];
}

}  // namespace Trie
```

<div STYLE="page-break-after: always;"></div>

## 4.3. AC Automaton
``` C++
// Aho-Corasick Automaton
#include <queue>
#include <string>

namespace Trie {
constexpr int N = 5e5, M = 26;

int trie[N][M];
int fail[N], have[M];
int cnt = 1;

void init() {
    std::fill(trie[0], trie[0] + M, 1);
}

void insert(std::string t) {
    int p = 1;
    for (auto c : t) {
        int x = c - 'a';
        if (!trie[p][x]) {
            trie[p][x] = ++cnt;
        }
        p = trie[p][x];
    }
    have[p] = 1;
}

void build() {
    std::queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        have[x] |= have[fail[x]];
        for (int i = 0; i < M; i++) {
            if (trie[x][i]) {
                fail[trie[x][i]] = trie[fail[x]][i];
                q.push(trie[x][i]);
            } else {
                trie[x][i] = trie[fail[x]][i];
            }
        }
    }
}

bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        p = trie[p][x];
        if (have[p]) {
            return true;
        }
    }
    return false;
}

}  // namespace Trie
```
