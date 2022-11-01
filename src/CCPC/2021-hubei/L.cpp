/**
 * @author: XiaFan
 * @date: 06-06 18:38
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include <bits/stdc++.h>

using i64 = long long;

template <typename T> class SegTree {
private:
    struct Node {
        T val;
        T tag;
        int cnt; // numbers can be modify
        Node() : val(0), tag(0), cnt(0) {}
    };
    int n;
    vector<Node> tree;
    int m_l(int root) { return root * 2 + 1; }
    int m_r(int root) { return root * 2 + 2; }
    void m_push_up(int root) {
        tree[root].val = tree[m_l(root)].val + tree[m_r(root)].val;
        // tree[root].cnt = tree[m_l(root)].cnt + tree[m_r(root)].cnt;
    }
    void m_build(int root, int left, int right, vector<T> &num) {
        assert(root < 4 * n);
        if (left == right) {
            tree[root].val = num[left];
            // tree[root].cnt = 1;
            return;
        }
        int mid = (left + right) / 2;
        m_build(m_l(root), left,    mid,   num);
        m_build(m_r(root), mid + 1, right, num);
        m_push_up(root);
    }
    void m_change(int root, int left, int right, T val) {
        tree[root].tag += val;
        // tree[root].val += (val * (right - left + 1));
        tree[root].val += (val * tree[root].cnt);
    }
    void m_push_down(int root, int left, int right) {
        int mid = (left + right) / 2;
        m_change(m_l(root), left,    mid,   tree[root].tag);
        m_change(m_r(root), mid + 1, right, tree[root].tag);
        tree[root].tag = 0;
    }
    void m_update(int root, int left, int right, int l, int r, int val) {
        assert(root < 4 * n);
        if (l <= left && right <= r) {
            m_change(root, left, right, val);
            return;
        }
        m_push_down(root, left, right);
        int mid = (left + right) / 2;
        if(l <= mid)     m_update(m_l(root), left,    mid,   l, r, val);
        if(mid + 1 <= r) m_update(m_r(root), mid + 1, right, l, r, val);
        m_push_up(root);
    }
    void m_cnt_update(int root, int left, int right, int pos, int val) {
        assert(root < 4 * n);
        tree[root].cnt += val;
        if(left == right) {
            return;
        }
        m_push_down(root, left, right);
        int mid = (left + right) / 2;
        if(pos <= mid) m_cnt_update(m_l(root), left,    mid,   pos, val);
        else           m_cnt_update(m_r(root), mid + 1, right, pos, val);
        m_push_up(root);
    }
    T m_query(int root, int left, int right, int l, int r) {
        assert(root < 4 * n);
        if (l <= left && right <= r) {
            return tree[root].val;
        }
        T ans = 0;
        m_push_down(root, left, right);
        int mid = (left + right) / 2;
        if(l <= mid)     ans += m_query(m_l(root), left,    mid,   l, r);
        if(mid + 1 <= r) ans += m_query(m_r(root), mid + 1, right, l, r);
        return ans;
    }

public:
    SegTree(vector<T> &num) : n(num.size()), tree(num.size() * 4) {
        m_build(0, 0, n - 1, num);
    }
    void update(int left, int right, int val) {
        m_update(0, 0, n - 1, left, right, val);
    }
    T query(int left, int right) {
        return m_query(0, 0, n - 1, left, right);
    }
    void cnt_update(int pos, int val) {
        assert(val == -1 || val == 1);
        m_push_down(0, 0, n - 1);
        m_cnt_update(0, 0, n - 1, pos, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> s(n);
    SegTree sg(a);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        if(s[i] == 1) {
            sg.cnt_update(i, 1);
        }
    }

    for(int i = 1; i <= q; i++) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            s[x - 1] = 0;
            sg.cnt_update(x - 1, -1);
        } else if(op == 2) {
            s[x - 1] = 1;
            sg.cnt_update(x - 1, 1);
        } else if(op == 3) {
            int y, val;
            cin >> y >> val;
            sg.update(x - 1, y - 1, val);
        } else {
            int y;
            cin >> y;
            cout << sg.query(x - 1, y - 1) << "\n";
        }
        // cerr << "[op: " << i << "] " << sg.query(0, n - 1) << "\n";
    }

    return 0;
}