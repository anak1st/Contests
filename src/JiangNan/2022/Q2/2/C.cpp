/**
 * @author: XiaFan
 * @date: 06-28 10:42
 **/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;

template <typename T> class SegmentTree {
private:
    struct node {
        int l, r;
        T sum;
        T tag;
        // int cnt = 0;  // numbers can be modify
        node() : sum(0), tag(0) {}
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
        // assert(root < 4 * n);
        tree[root].sum = tree[ls(root)].sum + tree[rs(root)].sum;
        // tree[root].sum = std::max(tree[ls(root)].sum, tree[rs(root)].sum);
        // tree[root].cnt = tree[m_l(root)].cnt + tree[m_r(root)].cnt;
    }

    void build(int root, const std::vector<T> &num) {
        // assert(root < 4 * n);
        if (tree[root].l == tree[root].r) {
            tree[root].sum = num[tree[root].l];
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
        // assert(root < 4 * n);
        tree[root].tag += val;
        tree[root].sum += (val * (tree[root].r - tree[root].l + 1));
        // tree[root].sum = val;
        // tree[root].sum += (val * tree[root].cnt);
    }
    
    void push_down(int root) {
        // assert(root < 4 * n);
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
    /*
    void cnt_update(int root, int left, int right, int pos, int val) {
        assert(root < 4 * n);
        tree[root].cnt += val;
        if (left == right) {
            return;
        }
        push_down(root, left, right);
        int mid = (left + right) / 2;
        if (pos <= mid) {
            cnt_update(ls(root), left, mid, pos, val);
        } else {
            cnt_update(rs(root), mid + 1, right, pos, val);
        }
        push_up(root);
    }
    */
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
    SegmentTree(const std::vector<T> &num) : n(num.size()), tree(num.size() * 4) {
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
    /*
    void cnt_update(int pos, int val) {
        assert(val == -1 || val == 1);
        push_down(0, 0, n - 1);
        cnt_update(0, 0, n - 1, pos, val);
    }
    */
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree<i64> sg(a);

    while (q--) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int x, y;
            cin >> x >> y;
            x--, y--;
            cout << sg.query(x, y) << "\n";
        } else if (c == 'C') {
            int x, y, b;
            cin >> x >> y >> b;
            x--, y--;
            sg.update(x, y, b);
        }
    }

    return 0;
}